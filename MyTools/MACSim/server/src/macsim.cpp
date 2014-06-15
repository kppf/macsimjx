//----------------------------------------------------------------------------
// MACSim.cpp
//
// Project : Multi-Agent Control in a Simulink block
// File    : MACSimServer class implementation
//
// Version : 1.0
// Date    : 9th February 2005
// Author  : Peter Mendham
//
// (c) University of York
//----------------------------------------------------------------------------

#include <stdio.h>
#include <conio.h>

#include "../include/macsim.h"

//----------------------------------------------------------------------------
// Config Server Function
//----------------------------------------------------------------------------

void ConfigServer::serverFunc(void* request, void* reply)
{
	DWORD requestCode = *((DWORD*)request);
	DWORD* replyPtr = (DWORD*)reply;
	
	// Pass on requests to the interface
	switch (requestCode)
	{	
	case MAC_CONFIG_CMD_INPUTS:
		*replyPtr = m_interface->getNumInputs();
		break;

	case MAC_CONFIG_CMD_OUTPUTS:
		*replyPtr = m_interface->getNumOutputs();
		break;

	case MAC_CONFIG_CMD_SAMPLE:
		*replyPtr = m_interface->getSampleInterval();
		break;

	default:
		*replyPtr = MAC_INVALID_RETURN;
	}
}

//----------------------------------------------------------------------------
// Sim Server Function
//----------------------------------------------------------------------------

void SimServer::serverFunc(void* request, void* reply)
{
	ColumnVectorAliasConstant inputs((double*)request, m_interface->getNumInputs());
	ColumnVectorAlias outputs((double*)reply, m_interface->getNumOutputs());
	
	// Pass on the request to the interface
	m_interface->getSimOutputs(inputs, outputs);
}

//----------------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------------

MACSimServer::MACSimServer(const char* p_name, MACSimServerInterface* p_interface) :
		m_name(p_name), m_isRunning(0), m_configServer(p_interface), m_simServer(p_interface)
{ }

//----------------------------------------------------------------------------
// Run function
//----------------------------------------------------------------------------

void MACSimServer::run(int showMessage, int waitForKey)
{
	// Run the system pipes
	m_configServer.run();
	m_simServer.run();
	
	// Running now
	m_isRunning = 1;
	
	if (showMessage)
	{
		// Display server launch message
		printf("MACSim Server: Running system \"%s\"\nPress any key to end service...", m_name.c_str());
	}

	if (waitForKey)
	{
		// Wait for key press
		if (getch() == 0) {
			getch();
		}
		
		// Terminate the server
		terminate();

		if (showMessage)
		{
			// Display final message
			printf("done.\n");
		}
	}
	
}
	
//----------------------------------------------------------------------------
// Terminate function
//----------------------------------------------------------------------------

void MACSimServer::terminate()
{
	// Only attempt to terminate if the server is actually running
	if (m_isRunning)
	{
		// Signal the system to terminate
		m_configServer.terminate();
		m_simServer.terminate();

		// Not running any more
		m_isRunning = 0;
	}
}

//----------------------------------------------------------------------------
