//----------------------------------------------------------------------------
// Server.cpp
//
// Project : Multi-Agent Control in a Simulink block
// File    : Native code for Server java class
// Package : macsim.internal
//
// Version : 1.0
// Date    : 16th February 2005
// Author  : Peter Mendham
//
// (c) University of York
//----------------------------------------------------------------------------

#include <stdio.h>
#include <windows.h>

#include "../include/macsim_internal_Server.h"

//----------------------------------------------------------------------------
// Useful definitions
//----------------------------------------------------------------------------

#define PIPE_TIMEOUT	(1000)

//----------------------------------------------------------------------------
// serverMain method
//----------------------------------------------------------------------------

JNIEXPORT void JNICALL Java_macsim_internal_Server_serverMain
(JNIEnv *env, jobject obj, jbyteArray inArray, jbyteArray outArray)
{
	HANDLE hTerminateEvent, hSynchroEvent;
	HANDLE hPipe, hEvents[2];
	DWORD dwWaitReturn, dwTemp;
	LPVOID lpvRequest, lpvReply;
	DWORD cbWritten, cbRead;
	OVERLAPPED gOverlapped;
	LPCTSTR lpszPipename;
	BOOL fSuccess;
	
	jclass cls;
	jfieldID fid;
	jstring jstrPipeName;
	jsize inBuffSize, outBuffSize;
	jmethodID mid;
	
	// Get our class
	cls = env->GetObjectClass(obj);
	
	// Collect sizes of request and reply buffers, in bytes
	inBuffSize = env->GetArrayLength(inArray);
	outBuffSize = env->GetArrayLength(outArray);
	
	// Collect method details for faster calling in loop
    mid = env->GetMethodID(cls, "serverFunc", "([B[B)V");
    if (mid == 0)
    {
		printf("Unable to locate serverFunc method");
		return;
    }
    
	// Read server pipe name
	fid = env->GetFieldID(cls, "pipeName", "Ljava/lang/String;");
	jstrPipeName = (jstring)env->GetObjectField(obj, fid);
	lpszPipename = env->GetStringUTFChars(jstrPipeName, 0);

	// Create server pipe
	hPipe = CreateNamedPipe(
		lpszPipename,				// pipe name
		PIPE_ACCESS_DUPLEX |      	// read/write access
		FILE_FLAG_OVERLAPPED,	  	// gOverlapped (asynchronous) mode
		PIPE_TYPE_MESSAGE |       	// message type pipe
		PIPE_READMODE_MESSAGE |   	// message-read mode
		PIPE_WAIT,               	// blocking mode
		1, 							// max. instances
		outBuffSize, 				// output buffer size
		inBuffSize,  				// input buffer size
		PIPE_TIMEOUT,             	// client time-out
		NULL);                    	// no security attribute

	// Release string
	env->ReleaseStringUTFChars(jstrPipeName, lpszPipename);	

	if (hPipe == INVALID_HANDLE_VALUE)
	{
		printf("Unable to create pipe");
		return;
	}

	// Create events
	hTerminateEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	hSynchroEvent = CreateEvent(NULL, FALSE, FALSE, NULL);
	
	// Set handles in object
	fid = env->GetFieldID(cls, "terminateEventHandle", "I");
	env->SetIntField(obj, fid, (jint)hTerminateEvent);
	fid = env->GetFieldID(cls, "synchEventHandle", "I");
	env->SetIntField(obj, fid, (jint)hSynchroEvent);

	// Copy handle to termination event
	hEvents[0] = hTerminateEvent;

	// Setup overlapped structure with required event
	ZeroMemory(&gOverlapped, sizeof(OVERLAPPED));
	hEvents[1] = CreateEvent(NULL, FALSE, FALSE, NULL);
	gOverlapped.hEvent = hEvents[1];

	// Loop until we are requested to terminate
	do
	{
		// Setup pipe connection
		ConnectNamedPipe(hPipe, &gOverlapped);

		// Wait for someone to connect to the pipe or for termination
		dwWaitReturn = WaitForMultipleObjects(2, hEvents, FALSE, INFINITE);

		// Check for an error
		if (dwWaitReturn == WAIT_FAILED)
			break;

		// Check to see if we got here because of the termination event
		if (dwWaitReturn == WAIT_OBJECT_0 ||
			dwWaitReturn == WAIT_ABANDONED_0)
		{
			break;
		}

		// Make sure we got woken because of pipe
		if (GetOverlappedResult(hPipe, &gOverlapped, &dwTemp, FALSE) == FALSE)
			break;

		// Loop to read and write whilst pipe is open
		do
		{
			// Collect pointer to request buffer
			lpvRequest = (LPVOID)env->GetByteArrayElements(inArray, 0);

			// Read client requests from the pipe.
			fSuccess = ReadFile(
				hPipe,        	// handle to pipe
				lpvRequest,    	// buffer to receive data
				inBuffSize, 	// size of buffer
				&cbRead,	 	// number of bytes read
				&gOverlapped);	// overlapped I/O

			// Check for error condition
			if (!fSuccess && GetLastError() != ERROR_IO_PENDING)
				break;

			// Wait for completion of read operation or for termination event
			dwWaitReturn = WaitForMultipleObjects(2, hEvents, FALSE, INFINITE);
			
			// Release request buffer, ensures changes are commited
			env->ReleaseByteArrayElements(inArray, (jbyte*)lpvRequest, 0);

			// Check for an error
			if (dwWaitReturn == WAIT_FAILED)
				break;

			// Check to see if we got here because of the termination event
			if (dwWaitReturn == WAIT_OBJECT_0 ||
				dwWaitReturn == WAIT_ABANDONED_0)
			{
				break;
			}

			// Make sure we got woken because of read
			if (GetOverlappedResult(hPipe, &gOverlapped, &dwTemp, FALSE) == FALSE)
				break;

			// Get response to request, call serverFunc method
			env->CallVoidMethod(obj, mid, inArray, outArray);

			// Collect pointer to reply buffer
			lpvReply = (LPVOID)env->GetByteArrayElements(outArray, 0);

			// Write the reply to the pipe.
			fSuccess = WriteFile(
				hPipe,        	// handle to pipe
				lpvReply,      	// buffer to write from
				outBuffSize, 	// number of bytes to write
				&cbWritten,   	// number of bytes written
				NULL);        	// not overlapped I/O

			// Release reply buffer, ensures changes are commited
			env->ReleaseByteArrayElements(outArray, (jbyte*)lpvReply, 0);

			// Check for error condition
			if (!fSuccess || cbWritten != outBuffSize)
				break;

		} while (WaitForSingleObject(hEvents[0], 0) != WAIT_OBJECT_0);

		// Disconnect named pipe at the server end
		fSuccess = DisconnectNamedPipe(hPipe);
		if (!fSuccess)
		{
			printf("Unable to disconnect pipe");
			break;
		}

	} while (WaitForSingleObject(hEvents[0], 0) != WAIT_OBJECT_0);

	// Destroy pipe synchronisation event
	CloseHandle(hEvents[1]);

	// Close the pipe.
	CloseHandle(hPipe);

	// Signal that we have finished
	SetEvent(hSynchroEvent);
}

//----------------------------------------------------------------------------
// terminateServer method
//----------------------------------------------------------------------------

JNIEXPORT void JNICALL Java_macsim_internal_Server_terminateServer
(JNIEnv *jenv, jobject jobjThis)
{
	HANDLE hTerminateEvent;
	HANDLE hSynchroEvent;
	jfieldID jfid;
	jclass jclsThis;
	
	// Get handles from object
	jclsThis = jenv->GetObjectClass(jobjThis);
	jfid = jenv->GetFieldID(jclsThis, "terminateEventHandle", "I");
	hTerminateEvent = (HANDLE)jenv->GetIntField(jobjThis, jfid);
	jfid = jenv->GetFieldID(jclsThis, "synchEventHandle", "I");
	hSynchroEvent = (HANDLE)jenv->GetIntField(jobjThis, jfid);
	
	// Signal the termination event
	SetEvent(hTerminateEvent);

	// Wait for the thread to quit
	WaitForSingleObject(hSynchroEvent, INFINITE);
	
	// Free up events
	CloseHandle(hTerminateEvent);
	CloseHandle(hSynchroEvent);
}

