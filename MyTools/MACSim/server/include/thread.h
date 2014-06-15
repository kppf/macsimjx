//----------------------------------------------------------------------------
// thread.h
//
// Project : Multi-Agent Control in a Simulink block
// File    : Thread class definitions
//
// Version : 1.0
// Date    : 9th February 2005
// Author  : Peter Mendham
//
// (c) University of York
//----------------------------------------------------------------------------

#ifndef __THREAD_H__
#define __THREAD_H__

#include <windows.h>

//----------------------------------------------------------------------------
// Thread class
//----------------------------------------------------------------------------

//! \brief Provides an object encapsulation for a Windows thread
//!
//! The thread class provides an easy way to create a class which has threaded
//! functionality.  The class provides simple encapsulation of the creation of
//! a thread, with synchronisation on termination.
class Thread
{

public:

	//! Constructor, initialises events and protection mutex
	Thread();

	//! Destructor, ensures the thread is terminated an frees members
	virtual ~Thread();

	//! \brief Run this thread
	//!
	//! Creates a thread and sets it running.  Does not return until the
	//! main() function signals it via the synchronisation event
	//! #m_hSynchroEvent.
	int run();

	//! \brief Terminate this thread
	//!
	//! Signals the thread main() routine to terminate via the termination
	//! event #m_hTerminateEvent.  Does not return until the main() function
	//! signals it via the synchronisation event #m_hSynchroEvent.
	void terminate();

protected:

	//! \brief Main routine, should be overridden to use thread
	//!
	//! The main function forms the body of the thread.  To synchronise with
	//! thre rest of the class the main function \b must carry out the
	//! following operations:
	//! \li Signal the sychronisation event #m_hSynchroEvent as soon as any
	//! initialisation has been carried out, this releases the run() function.
	//! \li Cease operating as quickly as possible when the termination event
	//! #m_hTerminateEvent is signalled.
	//! \li Signal the sychronisation event #m_hSynchroEvent as soon as any
	//! termination tasks have been carried out, this releases the terminate()
	//! function.  This should be the last thing a thread does.
	virtual int main();

	//! \brief The thread handle
	//!
	//! The handle of the running thread, or \c NULL if the thread is not
	//! running.
	HANDLE m_hThread;
	
	//! \brief The thread handle protection mutex
	//!
	//! This mutex must be acquired in order to read or write the thread
	//! handle #m_hThread.  This ensures the value read is always correct.
	HANDLE m_hMutex;
	
	//! \brief The synchronisation event
	//!
	//! Used once to idicate that the thread has completed initialisation and
	//! is running properly, freeing the run() function.  Used a second time,
	//! after the termination event #m_hTerminateEvent is signalled, to
	//! indicate that the thread has completed, freeing the terminate()
	//! function.
	HANDLE m_hSynchroEvent;
	
	//! \brief The termination event
	//!
	//! This event is signalled to indicate that the thread main() function
	//! should cease operating as soon as possible.
	HANDLE m_hTerminateEvent;

private:

	//! \brief Static kickstart routine
	//!
	//! This is the starting point for the new windows thread. A thread must
	//! be created to start in a static, or non-class member, function. When
	//! creating a thread a context pointer may be specified which is passed
	//! to the new thread.  The class instance pointer (\c this) is used in
	//! this case, which allows the kickstart function to call the main()
	//! member function.
	static DWORD WINAPI kickstart(LPVOID pClass)
	{
		return (DWORD)((Thread*)pClass)->main();
	}
};

//----------------------------------------------------------------------------

#endif // __THREAD_H__