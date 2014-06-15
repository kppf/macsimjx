//----------------------------------------------------------------------------
// macsim.h
//
// Project : Multi-Agent Control in a Simulink block
// File    : MACSimClient Sim class definition
//
// Version : 1.0
// Date    : 6th February 2005
// Author  : Peter Mendham
//
// (c) University of York
//----------------------------------------------------------------------------

#ifndef __MACSIM_H__
#define __MACSIM_H__

#include <sim.h>
#include "client.h"

//----------------------------------------------------------------------------
// The Sim class: MACSimClient
//----------------------------------------------------------------------------

//! \brief MACSim Simulink block class
//!
//! This class implements a simulink block using the SimClassLib library by
//! Lee Netherton.  This class implements a single discrete interface and
//! uses the Client class for named pipe interfacing to the MACSim server.
class MACSimClient : public Sim
{

private:

	//! \brief The Simulink block's discrete interface
	//!
	//! The discrete interface providing a single set of inputs and outputs
	//! which are mapped to those required/provided by the server.
	DiscreteInterface* m_interface;
	
	//! Pipe access client
	Client* m_client;
	
	//! \name IOPackets
	//! These packets are used for communicating simulation information to
	//! and from the Client class #m_client.
	//! \{
		
	//! \brief Input packet
	//!
	//! Input packet, uses IOPacket wrapper to allocate buffer automatically.
	//! Data must be copied into this buffer from the Simulink input vector.
	IOPacketWrapper* m_inPacket;
	
	//! \brief Output packet
	//!
	//! Output packet, does not have a buffer allocated as the buffer used
	//! internally by Simulink may be referenced.  This shortcut is not
	//! possible in the #m_inPacket case.
	IOPacket* m_outPacket;
	
	//! \}

public:

	//! \brief Constructor, creates classes.
	//!
	//! This is called by the SimClassLib library.  We create the pipe client
	//! and add the required discrete interface.  If any errors occurr a
	//! SimClassLib Exception is thrown.  The IOPacket classes are also
	//! created.
	//! \param s Internal Simulink configuration structure, used by
	//! SimClassLib
	MACSimClient(SimStruct *s);

	//! Destructor, frees classes.
	//!
	//! Simply deletes the #m_client, #m_inPacket and #m_outPacket members.
	//! SimClassLib handles the deletion of the interface.
	~MACSimClient();

	//! \name Simulation functions
	//!
	//! These functions are required by SimClassLib.  We only need the
	//! output() function.  All others are empty.
	//! \{
	
	//! \brief Updates Simulink output vector with data from the server.
	//!
	//! Uses the #m_client Client class to determine the required outputs for
	//! the inputs currently present in the interface input vector.
	virtual void output();

	//! Simulation function required by SimClassLib.  Empty.
	virtual void start() { }

	//! Simulation function required by SimClassLib.  Empty.
	virtual void init_cond() { }

	//! Simulation function required by SimClassLib.  Empty.
	virtual void update() { }

	//! Simulation function required by SimClassLib.  Empty.
	virtual void derivative() { }

	//! Simulation function required by SimClassLib.  Empty.
	virtual void terminate() { }
	
	//! \{
};

//----------------------------------------------------------------------------

#endif // __MACSIM_H__