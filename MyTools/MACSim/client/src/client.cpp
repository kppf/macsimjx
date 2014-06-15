//----------------------------------------------------------------------------
// client.cpp
//
// Project : Multi-Agent Control in a Simulink block
// File    : Client interface functions
//
// Version : 1.0
// Date    : 6th February 2005
// Author  : Peter Mendham
//
// (c) University of York
//----------------------------------------------------------------------------

#include <windows.h>

#include "../include/client.h"

//----------------------------------------------------------------------------
// Generic pipe open
//----------------------------------------------------------------------------

HANDLE Client::openPipe(const char* pipeName) const
{
	HANDLE hPipe;
	DWORD dwMode;
	BOOL fSuccess;

	do
	{
		// Open pipe connection with mac server
		hPipe = CreateFile(
			(LPTSTR)pipeName,		// pipe name
			GENERIC_READ |  		// read and write access
			GENERIC_WRITE,			//
			0,              		// no sharing
			NULL,           		// no security attributes
			OPEN_EXISTING,  		// opens existing pipe
			0,              		// default attributes
			NULL);          		// no template file

		// If we connected, set the pipe mode
		if (hPipe != INVALID_HANDLE_VALUE)
		{
			// Set the pipe mode to message read
			dwMode = PIPE_READMODE_MESSAGE;
			fSuccess = SetNamedPipeHandleState(
				hPipe,    			// pipe handle
				&dwMode,  			// new pipe mode
				NULL,     			// don't set maximum bytes
				NULL);    			// don't set maximum time

			// Check for success
			if (!fSuccess)
			{
				CloseHandle(hPipe);
				return INVALID_HANDLE_VALUE;
			}
		} 
		else
		{
			// We didn't connect, handle the error
			switch (GetLastError())
			{
				case ERROR_PIPE_BUSY:
				
					if (!WaitNamedPipe(pipeName, NMPWAIT_USE_DEFAULT_WAIT))
						throw ClientException("openPipe: Cannot connect, pipe is busy");
					break;
					
				case ERROR_FILE_NOT_FOUND:
				case ERROR_PATH_NOT_FOUND:
				
					throw ClientException("openPipe: Cannot connect, pipe not present");
					
				// REMOVE THIS WHEN ALL EXCEPTIONS ARE HANDLED
				default:
				
					throw ClientException("openPipe: Cannot connect, unknown error");
			}
		}

	} while (hPipe == INVALID_HANDLE_VALUE);

	return hPipe;
}

//----------------------------------------------------------------------------
// Generic configuration pipe data request
//----------------------------------------------------------------------------

unsigned int Client::configDataRequest(HANDLE hPipe, DWORD dwMsg) const
{
	DWORD dwReply, cbWritten, cbRead;
	BOOL fSuccess;

	// Write request to pipe
	fSuccess = WriteFile(
		hPipe,                  // pipe handle
		&dwMsg,                 // message
		sizeof(dwMsg),          // message length
		&cbWritten,             // bytes written
		NULL);                  // not overlapped

	// Check for success
	if (!fSuccess || cbWritten != sizeof(dwMsg))
		throw ClientException("configDataRequest: Unable to write to pipe");

	// Attempt to read response from pipe
	fSuccess = ReadFile(
		hPipe,    				// pipe handle
		&dwReply,  				// buffer to receive reply
		sizeof(dwReply),		// size of buffer
		&cbRead,  				// number of bytes read
		NULL);    				// not overlapped

	// Check for success
	if (!fSuccess || cbRead != sizeof(dwReply))
		throw ClientException("configDataRequest: Unable to read from pipe");
	
	// Check for invalid response
	if (dwReply == (DWORD)MAC_INVALID_RETURN)
		throw ClientException("configDataRequest: Invalid response code");

	return dwReply;
}

//----------------------------------------------------------------------------
// Request data from a pipe with pipe open
//----------------------------------------------------------------------------

unsigned int Client::configDataRequest(const char* pipeName, DWORD msgId) const
{
	HANDLE hConfigPipe;
	unsigned int response;
	
	// Open pipe
	hConfigPipe = openPipe(pipeName);
	
	// Perform the request
	response = configDataRequest(hConfigPipe, msgId);
	
	// Close the pipe
	CloseHandle(hConfigPipe);
	
	// Return response
	return response;
}


//----------------------------------------------------------------------------
// Initialise member data from configuration pipe if requested
//----------------------------------------------------------------------------

void Client::initialise(BOOL cacheData)
{
	HANDLE hConfigPipe;
	
	// Haven't opened simulation pipe yet
	m_simPipe = INVALID_HANDLE_VALUE;
	
	// Data not cached yet
	m_dataCached = FALSE;
	
	// Request data, if we've been asked
	if (cacheData)
	{
		// Open configuration pipe
		hConfigPipe = openPipe(MAC_CONFIG_PIPE_NAME);

		// Request configuration data
		m_inputs = configDataRequest(hConfigPipe, MAC_CONFIG_CMD_INPUTS);
		m_outputs = configDataRequest(hConfigPipe, MAC_CONFIG_CMD_OUTPUTS);
		m_sampleInterval = configDataRequest(hConfigPipe, MAC_CONFIG_CMD_SAMPLE);

		// Close configuration pipe
		CloseHandle(hConfigPipe);

		// Open simulation pipe
		m_simPipe = openPipe(MAC_SIM_PIPE_NAME);
		
		// We have cached all data
		m_dataCached = TRUE;
	}
}

//----------------------------------------------------------------------------
// Destructor
//----------------------------------------------------------------------------

Client::~Client()
{
	// Close simulation pipe
	if (m_simPipe != INVALID_HANDLE_VALUE)
		CloseHandle(m_simPipe);
}

//----------------------------------------------------------------------------
// Get outputs for this time interval from simulation pipe
//----------------------------------------------------------------------------

unsigned int Client::getSimOutputs(IOPacket* in, IOPacket* out) const
{
	DWORD cbWritten, cbRead, size;
	HANDLE hSimPipe = m_simPipe;
	BOOL fSuccess;
	
	// Open simulation pipe if necessary
	if (!m_dataCached)
		hSimPipe = openPipe(MAC_SIM_PIPE_NAME);

	// Write request to pipe
	size = in->m_nValues * sizeof(double);
	fSuccess = WriteFile(
		hSimPipe,				// pipe handle
		in->m_values,           // message
		size,					// size of buffer
		&cbWritten,             // number of bytes written
		NULL);                  // not overlapped

	// Check for success
	if (!fSuccess || cbWritten != size)
	{
		// Close simulation pipe if necessary
		if (!m_dataCached)
			CloseHandle(hSimPipe);
		
		// Throw exception
		throw ClientException("getSimOutputs: Unable to write to pipe");
	}

	// Attempt to read response from pipe
	size = out->m_nValues * sizeof(double);
	fSuccess = ReadFile(
		hSimPipe, 				// pipe handle
		out->m_values,			// buffer to receive reply
		size,					// size of buffer
		&cbRead,  				// number of bytes read
		NULL);    				// not overlapped

	// Check for success
	if (!fSuccess || cbRead != size)
	{
		// Close simulation pipe if necessary
		if (!m_dataCached)
			CloseHandle(hSimPipe);
		
		// Throw exception
		throw ClientException("getSimOutputs: Unable to read from pipe");
	}

	// Close simulation pipe if necessary
	if (!m_dataCached)
		CloseHandle(hSimPipe);
		
	return out->m_nValues;
}

//----------------------------------------------------------------------------
