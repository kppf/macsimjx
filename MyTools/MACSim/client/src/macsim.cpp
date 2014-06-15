//----------------------------------------------------------------------------
// MACSim.cpp
//
// Project : Multi-Agent Control in a Simulink block
// File    : Simulink interface code
//
// Version : 1.0
// Date    : 6th February 2005
// Author  : Peter Mendham
//
// (c) University of York
//----------------------------------------------------------------------------

//! \brief The name of the simulation class
//!
//! This definition is required by SimClassLib
#define SIM_CLASS_NAME 	MACSimClient

//! \brief The name of the library this class produces
//!
//! This definition is required by SimClassLib
#define SIM_FILE_NAME 	MACSim

// Get Doxygen to ignore these #defines, they make for confusing
// documentation.  For more information on these #defines, see the
// documentation for SimClassLib.
#ifndef DOXYGEN_SHOULD_SKIP_THIS

//----------------------------------------------------------------------------
// Declare the Sim class: MACSimClient
//----------------------------------------------------------------------------

#define SIM_CLASS_DECLARATION
#include "../include/macsim.h"

//----------------------------------------------------------------------------
// Define the Sim class: MACSimClient
//----------------------------------------------------------------------------

#define SIM_CLASS_DEFINITION
#include "sim.h"

#endif /* DOXYGEN_SHOULD_SKIP_THIS */



//----------------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------------

MACSimClient::MACSimClient(SimStruct *p_S) : Sim(p_S)
{

	// Haven't created anything yet
	m_client = NULL;
	m_inPacket = NULL;
	m_outPacket = NULL;

	// Attempt to construct a client pipe interface
	try
	{
		m_client = new Client();
	}
	catch (ClientException e)
	{
		// Re-throw as a sim Exception
		throw Exception(e.getDescription());
	}

	// Add a discrete interface that matches the inputs and outputs required
	// by the MACSim server.  We don't need any Simulink controlled states or
	// parameters.  MACSim uses a single sample time for both input and
	// output ports.
	m_interface = addDiscreteInterface("MACSim",
									   m_client->getNumInputs(), 
									   m_client->getNumOutputs(), 
									   0, 0, 
									   m_client->getSampleTime());
									   
	// Setup the input and output IOPackets
	m_inPacket = new IOPacketWrapper(m_client->getNumInputs());
	m_outPacket = new IOPacket(m_client->getNumOutputs());
}

//----------------------------------------------------------------------------
// Destructor
//----------------------------------------------------------------------------

MACSimClient::~MACSimClient()
{
	
	// Don't need to delete interface, this is done for us
	
	// Delete pipe client
	if (m_client != NULL) 
		delete m_client;

	// Delete the input and output IOPackets
	if (m_inPacket != NULL)
		delete m_inPacket;
	if (m_outPacket != NULL)
		delete m_outPacket;
}

//----------------------------------------------------------------------------
// Output function
//----------------------------------------------------------------------------

void MACSimClient::output()
{
	
	// Set the values, u must be copied
	for(int i = 0; i < m_inPacket->m_nValues; i++)
	{
		m_inPacket->m_values[i] = m_interface->u(i);
	}
	
	// However, there is a shortcut for y
	m_outPacket->m_values = &m_interface->y(0);
	
	// Request new outputs from the client
	m_client->getSimOutputs(m_inPacket, m_outPacket);
}

//----------------------------------------------------------------------------
