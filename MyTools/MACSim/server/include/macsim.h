//----------------------------------------------------------------------------
// MACSim.h
//
// Project : Multi-Agent Control in a Simulink block
// File    : MACSimServer class declaration
//
// Version : 1.0
// Date    : 9th February 2005
// Author  : Peter Mendham
//
// (c) University of York
//----------------------------------------------------------------------------

#ifndef __MACSIM_H__
#define __MACSIM_H__

#include <windows.h>
#include <string>

#include "matrix.h"

#include "server.h"
#include "../../include/interface.h"


//----------------------------------------------------------------------------
// MACSimServerInterface class
//----------------------------------------------------------------------------

//! \brief The interface for server implementations
//!
//! All classes intended to implement a server must inherit from
//! MACSimServerInterface.  This class is entirely abstract (all member
//! functions are pure virtual) and has no member variables.  It is modelled
//! after a Java interface and is therefore safe and easy to use for multiple
//! inheritance.  MACSimServerInterface contains four member functions, three
//! returning configuration information, one forming part of the simulation
//! cycle, returning output information for a given set of inputs.
class MACSimServerInterface
{
	
public:

	//! \name Configuration Functions
	//! These members should provide configuration information to the client.
	//! \{

	//! \brief Must return the number of inputs required by the server
	//!
	//! \return The number of inputs required.
	virtual unsigned int getNumInputs() = 0;

	//! \brief Must return the number of outputs provided by the server
	//!
	//! \return The number of outputs provided.
	virtual unsigned int getNumOutputs() = 0;
	
	//! \brief Must return the sampling frequency required by the server
	//!
	//! Should return the required sampling frequency in Hertz (samples per
	//! second).
	//! \return The sample interval required in Hertz.
	virtual unsigned int getSampleInterval() = 0;
	
	//! \}
	
	//! \name Simulation Functions
	//! This function carries out the main simulation task: returning a set of
	//! outputs for a given set of inputs.
	//! \{
	
	//! \brief Simulation function
	//!
	//! Should return a complete set of outputs for the specified set of
	//! inputs.  Typically called every sample period.
	//! \param in A column vector of input values obtained from the client
	//! \param out A column vector of output values to be sent to the client
	virtual void getSimOutputs(ColumnVectorAliasConstant& in, ColumnVectorAlias& out) = 0;
	
	//! \}
};

//----------------------------------------------------------------------------
// ConfigServer class
//----------------------------------------------------------------------------

//! \brief Configuration pipe server
//!
//! This class creates and manages an asynchronous named pipe for serving
//! configuration information to a MACSim client.  Information is obtained by
//! calling the MACSimServerInterface specified at construct time.
class ConfigServer : public Server
{
	
protected:

	//! The interface used to obtain configuration information
	MACSimServerInterface* m_interface;
	
	//! \brief %Server function, responds to configuration requests
	//!
	//! Receives a single \c DWORD request from the client and responds with
	//! a single \c DWORD answer obtained by calling the appropriate function
	//! on #m_interface.
	//! \param request A pointer to the request buffer, this will be
	//! \c sizeof(DWORD) bytes long
	//! \param reply A pointer to the reply buffer, this will be
	//! \c sizeof(DWORD) bytes long
	virtual void serverFunc(void* request, void* reply);

public:

	//! \brief Constructor, initialises Server parent as a configuration pipe
	//!
	//! Stores the interface pointer in member variable #m_interface and
	//! configures the Server as a configuration pipe handler.
	//! \li The server name is set to \c "configuration"
	//! \li The pipe name is set to ::MAC_CONFIG_PIPE_NAME
	//! \li input and output buffer sizes are set to \c sizeof(DWORD)
	//!
	//! \param p_interface The interface to use for obtaining configuration
	//! information.
	ConfigServer(MACSimServerInterface* p_interface) : 
		Server("configuration", MAC_CONFIG_PIPE_NAME, sizeof(DWORD), sizeof(DWORD))
	{ m_interface = p_interface; }
};

//----------------------------------------------------------------------------
// SimServer class
//----------------------------------------------------------------------------

//! \brief Simulation pipe server
//!
//! This class creates and manages an asynchronous named pipe for serving
//! simulation information to a MACSim client.  Information is obtained by
//! calling the MACSimServerInterface specified at construct time.
class SimServer : public Server
{
	
protected:

	//! The interface used to obtain simulation information
	MACSimServerInterface* m_interface;
	
	//! \brief %Server function, responds to simulation requests
	//!
	//! Receives a buffer of length \c sizeof(double) multiplied by the number
	//! of inputs specified by a call to the #m_interface member function
	//! MACSimServerInterface::getNumInputs().  The #m_interface member
	//! function MACSimServerInterface::getSimOutputs() is called to determine
	//! output information which is returned in the reply buffer.  The reply
	//! buffer has length \c sizeof(double) multiplied by the number of
	//! outputs specified by a call to the #m_interface member function
	//! MACSimServerInterface::getNumOutputs(). 
	//! \param request A pointer to the request buffer, this will be
	//! \c sizeof(double) times the number of inputs bytes long
	//! \param reply A pointer to the reply buffer, this will be
	//! \c sizeof(double) times the number of outputs bytes long
	virtual void serverFunc(void* request, void* reply);

public:

	//! \brief Constructor, initialises Server parent as a simulation pipe
	//!
	//! Stores the interface pointer in member variable #m_interface and
	//! configures the Server as a simulation pipe handler.  Numbers of
	//! inputs and outputs are obtained from the specified
	//! MACSimServerInterface.
	//! \li The server name is set to \c "simulation"
	//! \li The pipe name is set to ::MAC_SIM_PIPE_NAME
	//! \li input buffer size is set to \c sizeof(double) times the number
	//! of inputs.
	//! \li output buffer size is set to \c sizeof(double) times the number
	//! of outputs.
	//!
	//! \param p_interface The interface to use for obtaining simulation
	//! information.
	SimServer(MACSimServerInterface* p_interface) : 
		Server("simulation", 
			   MAC_SIM_PIPE_NAME, 
			   p_interface->getNumInputs()*sizeof(double), 
			   p_interface->getNumOutputs()*sizeof(double))
	{ m_interface = p_interface; }
};

//----------------------------------------------------------------------------
// MACSimServer class
//----------------------------------------------------------------------------

//! \brief A complete MACSim server
//!
//! A complete MACSim server, this class  creates and manages both
//! configuration and simulation pipes using information provided by calling
//! the MACSimServerInterface specified at construct time.
class MACSimServer
{
	
protected:

	//! The name of the server, used to display a running message to \c stdout
	string m_name;
	
	//! \brief Indicates whether the server is currently running
	//
	//! Non-zero indicates running, zero indicates currently terminated.
	int m_isRunning;
	
	//! The configuration pipe server
	ConfigServer m_configServer;
	
	//! The simulation pipe server
	SimServer m_simServer;

public:

	//! Constructor, itialises both pipes and member variables
	//!
	//! Initialises #m_name with p_name, and both pipes with the interface
	//! specified by p_interface.  Pipes are not started running until one of
	//! the run() member functions is called
	//! \param p_name The name of the server, used to generate running
	//! messages to \c stdout.
	//! \param p_interface The interface to use to service configuration and
	//! simulation pipe requests.
	MACSimServer(const char* p_name, MACSimServerInterface* p_interface);
	
	//! \brief Default run function
	//!
	//! Calls run(int,int) specifying non-zero for both showMessage and
	//! waitForKey.
	void run()
	{ run(1, 1); }

	//! \brief Run function
	//!
	//! Runs the server.  If showMessage is specified as non-zero a message is
	//! sent to \c stdout indicating that the server is running.  If
	//! waitForKey is specified as non-zero the server waits for a key press
	//! on \c stdin before terminating.  If waitForKey is specified, the
	//! server will terminate and then return.  If not, this function will
	//! return immediately, the server must then be terminated using the
	//! terminate() member function.
	//! \param showMessage If non-zero, running and termination messages are
	//! sent to \c stdout.
	//! \param waitForKey If non-zero, the function waits for a key press on
	//! \c stdin then terminates the server before returning.
	void run(int showMessage, int waitForKey);
	
	//! Terminate function, terminates the server if it is running
	void terminate();
};

//----------------------------------------------------------------------------

#endif // __MACSIM_H__