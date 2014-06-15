//----------------------------------------------------------------------------
// simple.cpp
//
// Project : Multi-Agent Control in a Simulink block
// File    : Simple example class
//
// Version : 1.0
// Date    : 15th February 2005
// Author  : Peter Mendham
//
// (c) University of York
//----------------------------------------------------------------------------

#include "macsim.h"

//----------------------------------------------------------------------------
// Simple example class
//----------------------------------------------------------------------------

//! \brief A simple example implementation of a MACSimServerInterface
//!
//! This class provides an example of how to create a MACSim server by
//! subclassing MACSimServerInterface.  This example expects two inputs, and
//! provides one output.  The output is expected to be provided at a 100Hz
//! sampling frequency.  At each sample time, the single output is calculated
//! simply as the sum of the two inputs.  To use this example a sample
//! Simulink model is provided in the same directory as this file.
class Simple : public MACSimServerInterface
{

public:

	//! Return the number of inputs required.  Always 2 in this example.
	virtual unsigned int getNumInputs()
	{ return 2; }
	
	//! Return the number of outputs provided.  Always 1 in this example.
	virtual unsigned int getNumOutputs()
	{ return 1; }
	
	//! Return the sampling frequency required.  Always 100Hz in this example.
	virtual unsigned int getSampleInterval()
	{ return 100; }
	
	//! \brief Use the inputs to calculate the output value
	//!
	//! The output value is the sum of the two inputs
	//! \param in The input column vector, this will be two elements long
	//! \param out The output column vector, this will be one element long
	//! (effectively a scalar).
	virtual void getSimOutputs(ColumnVectorAliasConstant& in, ColumnVectorAlias& out)
	{ out(0) = in(0) + in(1); }
	
};

//----------------------------------------------------------------------------
// Main function
//----------------------------------------------------------------------------

//! \brief Main function for the Simple example
//!
//! Creates an instance of the interface class Simple.  Then creates an
//! instance of the server class MACSimServer, passing it the interface.
//! Calls the MACSimServer::run() member function which does not return until
//! a key is pressed.  The program then terminates.
int main(void)
{
	Simple* simpleInterface = new Simple();
	MACSimServer simpleServer("Simple", simpleInterface);
	
	simpleServer.run();
	
	delete simpleInterface;
	
	return 0;
}

//----------------------------------------------------------------------------
