//----------------------------------------------------------------------------
// interface.h
//
// Project : Multi-Agent Control in a Simulink block
// File    : Client/Server interface definitions
//
// Version : 1.0
// Date    : 3rd August 2004
// Author  : Peter Mendham
//
// (c) University of York
//----------------------------------------------------------------------------

#ifndef __INTERFACE_H__
#define __INTERFACE_H__

//----------------------------------------------------------------------------
// Pipe names
//----------------------------------------------------------------------------

//! \name Pipe Names
//! The MACSim system uses two named pipes.  These names are defined here, and
//! only here, for the whole package.
//! \{

//! The string name of the configuration pipe.
#define MAC_CONFIG_PIPE_NAME		"\\\\.\\pipe\\MacSimConfig"

//! The string name of the simulation pipe.
#define MAC_SIM_PIPE_NAME			"\\\\.\\pipe\\MacSimSim"

//! \}

//----------------------------------------------------------------------------
// Protocol constants
//----------------------------------------------------------------------------

//! \name Protocol Constants
//! The configuration pipe requires all requests to be one of a predefined set
//! of constants. These constants are defined here, and only here, for the
//! whole package.
//! \{

//! Request for the number of inputs required by the server.
#define MAC_CONFIG_CMD_INPUTS		(0)

//! Request for the number of outputs provided by the server.
#define MAC_CONFIG_CMD_OUTPUTS		(1)

//! Request for the sample interval required by the server, in Hertz.
#define MAC_CONFIG_CMD_SAMPLE		(2)

//! \brief Returned by the server to indicate that a request did not succeed.
//!
//! Returned by the server to indicate that a request was not understood or
//! could not be processed.
#define MAC_INVALID_RETURN			(-1)

//! \}

//----------------------------------------------------------------------------
// IOPacket class
//----------------------------------------------------------------------------

//! \brief %Simple packet for input and output via the Client class
//!
//! The IOPacket class provides a simple packet structure to make the passing
//! of data to the MACSim server via the client easier.  This class does not
//! allocate memory for the #m_values buffer.  Use IOPacketWrapper for
//! convenient allocation/deallocation of this buffer.
class IOPacket {

public:

	//! The number of entries in the #m_values buffer
	unsigned int m_nValues;
	
	//! A buffer of \c double values
	double* m_values;
	
	//! \brief Constructor, initialises number of values
	//!
	//! Simply sets #m_nValues to match p_nValues
	//! \param p_nValues The number of values the #m_values buffer will
	//! support.
	IOPacket(const unsigned int p_nValues) {
		m_nValues = p_nValues;
	}
};

//----------------------------------------------------------------------------
// IOPacketWrapper class
//----------------------------------------------------------------------------

//! \brief A wrapper class for IOPacket
//!
//! IOPacketWrapper serves as a siple wrapper for an IOPacket adding
//! functionality which creates a buffer for the IOPacket::m_values buffer on
//! construction and frees the buffer on destruction.
class IOPacketWrapper : public IOPacket {
	
public:

	//! \brief Constructor, allocates buffer
	//!
	//! Creates a buffer of p_nValues entries of type \c double and assigns it
	//! to IOPacket::m_values.
	//! \param p_nValues The number of values the #m_values buffer will
	//! support, abuffer will be created of this size.
	IOPacketWrapper(const unsigned int p_nValues) : IOPacket(p_nValues) {
		m_values = new double[p_nValues];
	}
	
	//! Destructor, frees buffer
	~IOPacketWrapper() {
		delete[] m_values;
	}
};

#endif // __INTERFACE_H__