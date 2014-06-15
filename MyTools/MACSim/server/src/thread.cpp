//----------------------------------------------------------------------------
// thread.cpp
//
// Project : Multi-Agent Control in a Simulink block
// File    : Thread class implementation
//
// Version : 1.0
// Date    : 9th February 2005
// Author  : Peter Mendham
//
// (c) University of York
//----------------------------------------------------------------------------

#include "../include/thread.h"

//----------------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------------

Thread::Thread()
{
	// Default to a thread handle of null
	m_hThread = NULL;

	// Setup a synchronisation event for reverse communication
	m_hSynchroEvent = CreateEvent(NULL, FALSE, FALSE, NULL);

	// ...and a termination event to signal termination
	m_hTerminateEvent = CreateEvent(NULL, TRUE, FALSE, NULL);

	// Setup a mutex to guard our critical sections, these are where the
	// thread handle, hThread, is accessed to check for a NULL
	m_hMutex = CreateMutex(NULL, FALSE, NULL);
}

//----------------------------------------------------------------------------
// Destructor
//----------------------------------------------------------------------------

Thread::~Thread()
{
	// If the thread has not yet terminated, terminate it
	if (m_hThread != NULL)
		terminate();

	// Release the events
	CloseHandle(m_hSynchroEvent);
	CloseHandle(m_hTerminateEvent);

	// Release our mutex
	CloseHandle(m_hMutex);
}

//----------------------------------------------------------------------------
// Run the thread
//----------------------------------------------------------------------------

int Thread::run()
{
	DWORD dwThreadId;

	// Check we have all necessary objects allocated
	if (m_hSynchroEvent == NULL    ||
		m_hTerminateEvent == NULL  ||
		m_hMutex == NULL)
	{
		return -1;
	}

	// Acquire the mutex
	WaitForSingleObject(m_hMutex, INFINITE);

	// Only create a thread if there isn't one already
	if (m_hThread != NULL)
	{
		ReleaseMutex(m_hMutex);
		return 0;
	}

	// Start off a thread
	m_hThread = CreateThread(NULL, 4096, kickstart, (PVOID)this, 0, &dwThreadId);

	// Check thread is setup OK
	if (m_hThread == NULL)
	{
		ReleaseMutex(m_hMutex);
		return -1;
	}

	// Release the mutex
	ReleaseMutex(m_hMutex);

	// Wait for thread to complete start routine
	WaitForSingleObject(m_hSynchroEvent, INFINITE);

	// Return successful code
	return 0;
}

//----------------------------------------------------------------------------
// terminate the thread
//----------------------------------------------------------------------------

void Thread::terminate()
{
	// Acquire the mutex
	WaitForSingleObject(m_hMutex, INFINITE);

	// Check if we have a thread
	if (m_hThread != NULL)
	{
		// Signal the termination event
		SetEvent(m_hTerminateEvent);

		// Wait for the thread to quit
		WaitForSingleObject(m_hSynchroEvent, INFINITE);

		// Release the thread handle
		CloseHandle(m_hThread);

		// Set the handle to NULL
		m_hThread = NULL;
	}

	// Release the mutex
	ReleaseMutex(m_hMutex);
}

//----------------------------------------------------------------------------
// The thread's default main function
//----------------------------------------------------------------------------

int Thread::main()
{
	// Signal that we have started
	SetEvent(m_hSynchroEvent);

	// Wait for termination event
	WaitForSingleObject(m_hTerminateEvent, INFINITE);

	// Signal that we have finished
	SetEvent(m_hSynchroEvent);

	return 0;
}

//----------------------------------------------------------------------------

