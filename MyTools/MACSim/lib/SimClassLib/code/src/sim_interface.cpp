#include "../include/sim_interface.h"
#include "../include/sim_class.h"
#include "../include/sim_exception.h"


//------------------------------------------------------------
//         Interface
//------------------------------------------------------------

// Constructor
Interface::Interface(InterfaceContainer * p_interfaceContainer, const char * p_name, const unsigned int p_inputs, const unsigned int p_outputs, const unsigned int p_params) :
	m_interfaceContainer(p_interfaceContainer),
	m_name(p_name),
	u(this,p_inputs),
	y(this,p_outputs),
	param(this,p_params)
{}

// Print Ip details
void Interface::printInfo() const
{
	printf("IP info:\n");
	printf("Inputs: \t%d\n",getNumInputs());
	printf("Outputs:\t%d\n",getNumOutputs());
	printf("States: \t%d\n",getNumStates());
	printf("Params: \t%d\n",getNumParams());
}

//------------------------------------------------------------
//         ContiuousInterface
//------------------------------------------------------------

// Constructor
ContinuousInterface::ContinuousInterface(InterfaceContainer * p_interfaceContainer, const char * p_name, const unsigned int p_inputs, const unsigned int p_outputs, const unsigned int p_states, const unsigned int p_params) :
	Interface(p_interfaceContainer, p_name, p_inputs, p_outputs, p_params), x(this,p_states), dx(this,p_states)
{}

//------------------------------------------------------------
//         DiscreteInterface
//------------------------------------------------------------

DiscreteInterface::DiscreteInterface(InterfaceContainer * p_interfaceContainer, const char * p_name, const unsigned int p_inputs, const unsigned int p_outputs, const unsigned int p_states, const unsigned int p_params,
									 const double p_inputSampleTime, const double p_outputSampleTime, const double p_inputSampleOffset = 0.0, const double p_outputSampleOffset = 0.0) :
	Interface(p_interfaceContainer, p_name, p_inputs, p_outputs, p_params), x(this,p_states)
{
	// Check sample times for validity
	if (p_inputSampleTime <= 0.0)
		throw Exception("Invalid input sample time");
	if (p_inputSampleOffset <= 0.0)
		throw Exception("Invalid input sample time offset");
	if (p_outputSampleTime <= 0.0)
		throw Exception("Invalid output sample time");
	if (p_outputSampleOffset <= 0.0)
		throw Exception("Invalid output sample time offset");

	// Copy sample times
	m_inputSampleTime = p_inputSampleTime;
	m_inputSampleOffset = p_inputSampleOffset;
	m_outputSampleTime = p_outputSampleTime;
	m_outputSampleOffset = p_outputSampleOffset;
}


DiscreteInterface::DiscreteInterface(InterfaceContainer * p_interfaceContainer, const char * p_name, const unsigned int p_inputs, const unsigned int p_outputs, const unsigned int p_states, const unsigned int p_params, const double p_sampleTime) :
	Interface(p_interfaceContainer, p_name, p_inputs, p_outputs, p_params), x(this,p_states)
{
	// Check sample time for validity
	if (p_sampleTime <= 0.0)
		throw Exception("Invalid input sample time");

	// Set up sample times
	m_inputSampleTime = p_sampleTime;
	m_inputSampleOffset = 0.0;
	m_outputSampleTime = p_sampleTime;
	m_outputSampleOffset = 0.0;
}

