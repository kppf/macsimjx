//----------------------------------------------------------------------------
// server.cpp
//
// Project : Multi-Agent Control in a Simulink block
// File    : Server class implementation
//
// Version : 1.0
// Date    : 9th February 2005
// Author  : Peter Mendham
//
// (c) University of York
//----------------------------------------------------------------------------

#include <stdio.h>

#include "../include/server.h"

//----------------------------------------------------------------------------
// Defined pipe timeout time in milliseconds
//----------------------------------------------------------------------------

const int Server::PIPE_TIMEOUT = 1000;

//----------------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------------

Server::Server(const char* p_serverName, const char* p_pipeName, int p_inBuffSize, int p_outBuffSize)
{
	// Setup strings
	m_serverName = p_serverName;
	m_pipeName = p_pipeName;

	// Copy buffer sizes
	m_inBuffSize = p_inBuffSize;
	m_outBuffSize = p_outBuffSize;
}

//----------------------------------------------------------------------------
// Destructor
//----------------------------------------------------------------------------

Server::~Server()
{
	// Make sure thread has finished
	terminate();
}

//----------------------------------------------------------------------------
// Main function
//----------------------------------------------------------------------------

int Server::main()
{
	HANDLE hPipe, hEvents[2];
	DWORD dwWaitReturn, dwTemp;
	LPVOID lpvRequest, lpvReply;
	DWORD cbWritten, cbRead;
	OVERLAPPED gOverlapped;
	BOOL fSuccess;

	// Signal that we have started
	SetEvent(m_hSynchroEvent);

	// Create server pipe
	hPipe = CreateNamedPipe(
		m_pipeName.c_str(),			// pipe name
		PIPE_ACCESS_DUPLEX |      	// read/write access
		FILE_FLAG_OVERLAPPED,	  	// gOverlapped (asynchronous) mode
		PIPE_TYPE_MESSAGE |       	// message type pipe
		PIPE_READMODE_MESSAGE |   	// message-read mode
		PIPE_WAIT,               	// blocking mode
		1, 							// max. instances
		m_outBuffSize, 				// output buffer size
		m_inBuffSize,  				// input buffer size
		PIPE_TIMEOUT,             	// client time-out
		NULL);                    	// no security attribute

	if (hPipe == INVALID_HANDLE_VALUE)
	{
		printf("\n\tFatal Error: Unable to create %s pipe (%d)\n", m_serverName.c_str(), GetLastError());
		return 1;
	}

	// Create request and reply buffers
	lpvRequest = LocalAlloc(LMEM_FIXED, m_inBuffSize);
	if (lpvRequest == NULL)
	{
		printf("\n\tFatal Error: Unable to allocate input buffer for %s pipe\n", m_serverName.c_str());
		CloseHandle(hPipe);
		return 2;
	}
	
	lpvReply = LocalAlloc(LMEM_FIXED, m_outBuffSize);
	if (lpvReply == NULL)
	{
		printf("\n\tFatal Error: Unable to allocate output buffer for %s pipe\n", m_serverName.c_str());
		LocalFree(lpvRequest);
		CloseHandle(hPipe);
		return 3;
	}

	// Copy handle to termination event
	hEvents[0] = m_hTerminateEvent;

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
			// Read client requests from the pipe.
			fSuccess = ReadFile(
				hPipe,        	// handle to pipe
				lpvRequest,    	// buffer to receive data
				m_inBuffSize, 	// size of buffer
				&cbRead,	 	// number of bytes read
				&gOverlapped);	// overlapped I/O

			// Check for error condition
			if (!fSuccess && GetLastError() != ERROR_IO_PENDING)
				break;

			// Wait for completion of read operation of for termination event
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

			// Make sure we got woken because of read
			if (GetOverlappedResult(hPipe, &gOverlapped, &dwTemp, FALSE) == FALSE)
				break;

			// Get response to request
			serverFunc(lpvRequest, lpvReply);

			// Write the reply to the pipe.
			fSuccess = WriteFile(
				hPipe,        	// handle to pipe
				lpvReply,      	// buffer to write from
				m_outBuffSize, 	// number of bytes to write
				&cbWritten,   	// number of bytes written
				NULL);        	// not overlapped I/O

			// Check for error condition
			if (!fSuccess || cbWritten != m_outBuffSize)
				break;

		} while (WaitForSingleObject(hEvents[0], 0) != WAIT_OBJECT_0);

		// Disconnect named pipe at the server end
		fSuccess = DisconnectNamedPipe(hPipe);
		if (!fSuccess)
		{
			printf("\n\tFatal Error: Unable to disconnect %s pipe (%d)\n", m_serverName, GetLastError());
			break;
		}

	} while (WaitForSingleObject(hEvents[0], 0) != WAIT_OBJECT_0);

	// Destroy pipe synchronisation event
	CloseHandle(hEvents[1]);

	// Free input and output buffers
	LocalFree(lpvRequest);
	LocalFree(lpvReply);

	// Close the pipe.
	CloseHandle(hPipe);

	// Signal that we have finished
	SetEvent(m_hSynchroEvent);

	return 0;
}

//----------------------------------------------------------------------------
