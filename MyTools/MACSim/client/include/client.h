//----------------------------------------------------------------------------
// client.h
//
// Project : Multi-Agent Control in a Simulink block
// File    : Client class declaration
//
// Version : 1.0
// Date    : 6th February 2005
// Author  : Peter Mendham
//
// (c) University of York
//----------------------------------------------------------------------------

#ifndef __CLIENT_H__
#define __CLIENT_H__

#include <windows.h>

#include "../../include/interface.h"

//----------------------------------------------------------------------------
// ClientException class
//----------------------------------------------------------------------------

//! \brief Exception class to be thrown by the pipe client
//! \author Peter Mendham
class ClientException
{
	
protected:

	//! \brief Exception description
	//!
	//! Set to "General Exception", if default constructor is used
	const char* m_desc;

public:

	//! \brief Default constructor
	//!
	//! Constructs the exception with the default description
	//! "General Exception"
	ClientException()
	{
		m_desc = "General exception";
	}

	//! \brief Constructor with description
	//!
	//! Constructs the exception with the description string
	//! specified.
	//! \param p_desc A string describing the cause of the exception.
	ClientException(const char *p_desc)
	{
		m_desc = p_desc;
	}

	//! Accessor for description string
	//! \return A string describing the cause of the exception.
	const char* getDescription() const
	{
		return m_desc;
	}
};

//----------------------------------------------------------------------------
// Client class
//----------------------------------------------------------------------------

//! \brief Windows pipe client class
//! \author Peter Mendham
//!
//! This class is a generic pipe client, intended for use with the MACSim
//! server.  The client represents the functionality of the server across
//! the named pipe set.
//!
//! A MACSim client has four operations split into two groups.  The first
//! group is made up of configuration operations.  Each operation is a
//! request for configuration information from the server.  Three different
//! requests are possible:
//! \li the number of inputs required by the server system;
//! \li the number of outputs provided by the server system;
//! \li the regular sampling frequency in Hertz (samples per second).
//!
//! There is one simulation operation, the simulation update.  In this case
//! the client accepts a set of values, one for each input.  These are
//! conveyed to the server which responds with a value for each output.
//! The client deals with inputs and outputs each in the form of an IOPacket.
//!
//! There are two main methods of using the client class: cached and
//! uncached modes.  The cached mode is intended for general use.  On
//! construction the client class queries the server for configuration data.
//! These data are stored and recalled using accessors.  Thus configuration
//! is queried only once.  Simulation data is queried on demand, but the
//! simulation pipe is kept open continuously, for speed.  Uncached mode is
//! largely intended for testing purposes.  In this case the class does very
//! little on construction.  No data are stored.  Data are requested
//! explicitly whenever accessor functions are called.  The simulation pipe
//! is normally closed, and is opened only to request a new set of output
//! data.
class Client
{
	
private:
	
	//! \brief Indicates whether configuration data is cached or not.
	//!
	//! This member will be \c TRUE if configuration data is cached in the
	//! data members #m_inputs, #m_outputs and #m_sampleInterval.  The simulation
	//! pipe will also be held open with its handle stored in #m_simPipe.
	BOOL m_dataCached;
	
	//! \name Data for Cached Mode
	//! These members are not used in uncached mode.  The boolean member
	//! m_dataCached indicates whether these variables are in use or not.
	//! \{
		
	//! The handle of the simulation pipe held open in cached mode
	HANDLE m_simPipe;
	
	//! The number of inputs required by the server
	unsigned int m_inputs;
	
	//! The number of outputs provided by the server
	unsigned int m_outputs;
	
	//! The sampling frequency required by the server, in Hertz
	unsigned int m_sampleInterval;
	
	//! \}
	
protected:

	//! \brief Open a pipe of the given name
	//!
	//! Opens a windows named pipe of the given name and form a connection to
	//! it.  The pipe should be closed using a CloseHandle windows API call.
	//! Throws a ClientException on error.
	//! \param pipeName The ASCII string name of the pipe to open
	//! \exception ClientException
	//! \return The handle of the pipe
	HANDLE openPipe(const char* pipeName) const;
	
	//! \brief Request data from an open pipe
	//!
	//! Requests data from the pipe with the supplied handle.  Sends the
	//! supplied \c DWORD msgId to the server and expects a single \c DWORD
	//! in response.  The response value is returned as an \c unsigned \c int.
	//! Throws a ClientException on error.
	//! \param hPipe The handle of the pipe to use.
	//! \param msgId A \c DWORD value to send to the server.
	//! \exception ClientException
	//! \return The data returned by the server.
	unsigned int configDataRequest(HANDLE hPipe, DWORD msgId) const;
	
	//! \brief Request data from a pipe with pipe open
	//!
	//! This function first opens the pipe with the name supplied then
	//! executes a configDataRequest() on the opened pipe sending
	//! the msgId specified as data.  The return value of the 
	//! configDataRequest() call is return to the caller after
	//! the is closed.
	//! \param pipeName The ASCII string name of the pipe to open
	//! \param msgId A \c DWORD value to send to the server.
	//! \exception ClientException
	//! \return The data returned by the server.
	unsigned int configDataRequest(const char* pipeName, DWORD msgId) const;
	
	//! \brief Initialise member data including cached data if requested
	//!
	//! All member data are initialised with default values.  If cacheData is
	//! \c TRUE then configuration data members are initialised with values 
	//! obtained from the server across the configuration pipe.  The
	//! simulation pipe is also opened, its handle is stored in #m_simPipe.
	//! #m_dataCached is set to the value of cacheData.
	//! \param cacheData Set to \c TRUE to initialise cache data members with
	//! configuration data from the server.
	void initialise(BOOL cacheData);
	
public:

	//! \brief Default Constructor
	//! 
	//! Constructs a pipe client in cached mode.
	Client()
	{
		initialise(TRUE);
	}
	
	//! \brief Explicit Constructor
	//!
	//! Allows the class to be constructed in cached and uncached modes.
	//! \param cacheData Set to \c TRUE to construct the class in cached mode.
	Client(BOOL cacheData)
	{
		initialise(cacheData);
	}

	//! \brief Destructor
	//!
	//! Ensures the simulation pipe is closed.
	~Client();
	
	//! \name Configuration Data Request Functions
	//! These functions explicitly request configuration data from the server.
	//! Cached data is not used, and returned data is not cached.  The
	//! configuration pipe will be opened, the item of data requested, then
	//! the pipe will be closed.
	//! \{
		
	//! \brief Request the number of inputs.
	//!
	//! Requests the number of inputs required by the server.
	//! \return The number of inputs required by the server.
	unsigned int requestNumInputs() const
	{
		return configDataRequest(MAC_CONFIG_PIPE_NAME, MAC_CONFIG_CMD_INPUTS);
	}
	
	//! \brief Request the number of outputs.
	//!
	//! Requests the number of outputs provided by the server.
	//! \return The number of outputs provided by the server.
	unsigned int requestNumOutputs() const
	{
		return configDataRequest(MAC_CONFIG_PIPE_NAME, MAC_CONFIG_CMD_OUTPUTS);
	}
	
	//! \brief Request the sample interval.
	//!
	//! Requests the sampling frequency required by the server.  This
	//! frequency is assumed to be fixed.
	//! \return The sample period required by the server in Hertz.
	unsigned int requestSampleInterval() const
	{
		return configDataRequest(MAC_CONFIG_PIPE_NAME, MAC_CONFIG_CMD_SAMPLE);
	}
	
	//! \brief Request the sample period.
	//!
	//! Requests the period between samples required by the server.  This
	//! period is assumed to be fixed.
	//! \return The sample period required by the server in seconds.
	double requestSampleTime() const
	{
		return 1 / (double)requestSampleInterval();
	}

	//! \}
	
	//! \name Configuration Data Accessor Functions
	//! The behaviour of these functions is dependent on the operating mode of
	//! the class.  In cached mode these functions return cached data and
	//! no pipe transaction is involved in their use.  In uncached mode these
	//! functions behave identically to their request counterparts.
	//! \{
		
	//! \brief Get the number of inputs.
	//!
	//! Returns the number of inputs required by the server.  Either from
	//! cached data or an explicit request via a call to requestNumInputs().
	//! \return The number of inputs required by the server.
	unsigned int getNumInputs() const
	{
		if (m_dataCached)
			return m_inputs;
		else
			return requestNumInputs();
	}
	
	//! \brief Get the number of outputs.
	//!
	//! Returns the number of outputs provided by the server.  Either from
	//! cached data or an explicit request via a call to requestNumOutputs().
	//! \return The number of outputs provided by the server.
	unsigned int getNumOutputs() const
	{
		if (m_dataCached)
			return m_outputs;
		else
			return requestNumOutputs();
	}
	
	//! \brief Get the sample interval.
	//!
	//! Returns the sampling frequency required by the server.  This
	//! frequency is assumed to be fixed.  Either from cached data or an
	//! explicit request via a call to requestSampleInterval().
	//! \return The sample period required by the server in Hertz.
	unsigned int getSampleInterval() const
	{
		if (m_dataCached)
			return m_sampleInterval;
		else
			return requestSampleInterval();
	}
	
	//! \brief Get the sample period.
	//!
	//! Returns the period between samples required by the server.  This
	//! period is assumed to be fixed.  getSampleInterval() is used to
	//! calculate this data.
	//! \return The sample period required by the server in seconds.
	double getSampleTime() const
	{
		return 1 / (double)getSampleInterval();
	}
	
	//! \}
	
	//! \name Simulation Data Request Functions
	//! The operation of this function again depends on the mode of the class.
	//! In both modes output data is requested from the server when the
	//! function is called. In cached mode the simulation pipe is kept open
	//! between call, whereas in uncached mode the simulation pipe is opened
	//! on demand.
	//! \{
	
	//! \brief Get a new set of outputs from the server.
	//!
	//! Present the server with a set of outputs and request a new set of
	//! inputs.  The number of inputs must match the number specified by
	//! either the getNumInputs() or the requestNumInputs() function.  The
	//! number of outputs must match the number specified by either the
	//! getNumInputs() or the requestNumInputs() function.  The
	//! IOPacketWrapper class can be used to handle the allocation of
	//! IOPacket memory easily.
	//!
	//! \param in The input IOPacket.  This should be correctly sized for
	//! the number of inputs.
	//! \param out The output IOPacket.  This should be correctly sized for
	//! the number of outputs.
	unsigned int getSimOutputs(IOPacket* in, IOPacket* out) const;
	
	//! \}
};

//----------------------------------------------------------------------------

#endif // __CLIENT_H__