//----------------------------------------------------------------------------
// server.h
//
// Project : Multi-Agent Control in a Simulink block
// File    : Server class declaration
//
// Version : 1.0
// Date    : 6th February 2005
// Author  : Peter Mendham
//
// (c) University of York
//----------------------------------------------------------------------------

#ifndef __SERVER_H__
#define __SERVER_H__

#include <windows.h>
#include <iostream>

#include "thread.h"

//----------------------------------------------------------------------------
// Server class
//----------------------------------------------------------------------------

//! \brief A generic, asynchronous pipe server
//!
//! This class implements a simple generic pipe server, which uses a separate
//! thread to service pipe requests asynchronously.  The server expects fixed
//! length input and output buffers, the length of which are specified at
//! construction time.  This class should be overridden for general use,
//! redefining the serverFunc() method to provide functionality.
class Server : public Thread {

protected:

	//! \brief Server function, should be overridden.
	//!
	//! This function should be overridden by child classes to provide pipe
	//! functionality. Data in the request buffer should be used to fill the
	//! reply buffer with a suitable response.
	//! \param request A pointer to the request buffer, this will be
	//! #m_inBuffSize bytes long
	//! \param reply A pointer to the reply buffer, this will be
	//! #m_outBuffSize bytes long
	virtual void serverFunc(void* request, void* reply) { }

	//! \brief Main thread function, creates and operates the pipe
	//!
	//! The main function runs in a separate thread, created by the parent
	//! Thread class.  A pipe, with name #m_pipeName is created.  The main
	//! function then waits for a request on the pipe or the termination
	//! event Thread::m_hTerminateEvent.  If a request is received it is
	//! passed to the serverFunc().  The response from serverFunc() (in the
	//! reply buffer) is sent down the pipe as a reply.
	virtual int main();

	//! \name Pipe server parameters
	//! Theses parameters are specified by the constructor and used for
	//! configuration of the server.
	//! \{
		
    //! \brief The name of the server
    //!
    //! This description is used to identify the server in exception messages.
    string m_serverName;
    
    //! \brief The name of the pipe
    //!
    //! This should contain the full path of the named pipe.
	string m_pipeName;
	
	//! \brief The size of input buffer, in bytes
	//!
	//! Requests to the server should all be of this size.
	int  m_inBuffSize;

	//! \brief The size of output buffer, in bytes
	//!
	//! Replies from the server should all be of this size.
	int  m_outBuffSize;
	
	//! \}

	//! \brief Defines the pipe timeout time in milliseconds
	//!
	//! This value must be specified, but its use does not affect the
	//! operation of the server.  It is defined here, rather than being
	//! hardcoded, for readability.
	static const int PIPE_TIMEOUT;

public:

	//! \brief Constructor initialises the server, does not run server thread
	//!
	//! \param p_serverName The name of the server, used only to identify the
	//! server in an exception message.  Used to intialise #m_serverName
	//! \param p_pipeName The full path of the named pipe.  Used to intialise
	//! #m_pipeName.
	//! \param p_inBuffSize The required size of the input buffer, in bytes.
	//! Used to initialise #m_inBuffSize.
	//! \param p_outBuffSize The required size of the output buffer, in bytes.
	//! Used to initialise #m_outBuffSize.
	Server(const char* p_serverName, const char* p_pipeName, int p_inBuffSize, int p_outBuffSize);

	//! Destructor, ensures the server thread has terminated.
	~Server();
	
};

//----------------------------------------------------------------------------

#endif // __SERVER_H__

//21 August 2010 - changed iostream.h to iostream since the first form is deprecated