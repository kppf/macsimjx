#include "../include/sim_interface_container.h"
#include "../include/sim_interface.h"
#include "../include/sim_exception.h"
#include "../include/sim_class.h"

// Constant
const double InterfaceContainer::SAMPLE_TIME_CONTINUOUS = -1.0;
const double InterfaceContainer::SAMPLE_OFFSET_CONTINUOUS = -1.0;

// Constuctor
InterfaceContainer::InterfaceContainer(Sim * p_sim) : m_sim(p_sim)
{}

// Destructor
InterfaceContainer::~InterfaceContainer()
{
	// Delete continuous interfaces
	for (int i = 0; i < m_vecContInterface.size(); i++)
	{
		delete m_vecContInterface[i];
	}

	// And now do the same for discrete interfaces
	for (int i = 0; i < m_vecDiscInterface.size(); i++)
	{
		delete m_vecDiscInterface[i];
	}
}

ContinuousInterface * InterfaceContainer::addContinuousInterface(const char * p_name, const unsigned int p_inputs, const unsigned int p_outputs, const unsigned int p_states, const unsigned int p_params)
{
	// Store current size of ip vector
	int id = m_vecContInterface.size();

	// Create new ip at position `id'
	m_vecContInterface.push_back(new ContinuousInterface(this, p_name, p_inputs, p_outputs, p_states, p_params));

	// Return a pointer to the new ContinuousInterface
	return m_vecContInterface[id];
}

DiscreteInterface * InterfaceContainer::addDiscreteInterface(const char * p_name, const unsigned int p_inputs, const unsigned int p_outputs, const unsigned int p_states, const unsigned int p_params,
															 const double p_inputSampleTime, const double p_outputSampleTime, const double p_inputSampleOffset = 0.0, const double p_outputSampleOffset = 0.0)
{
	// Store current size of ip vector
	int id = m_vecDiscInterface.size();

	// Create new ip at position `id'
	m_vecDiscInterface.push_back(new DiscreteInterface(this, p_name, p_inputs, p_outputs, p_states, p_params, p_inputSampleTime, p_outputSampleTime, p_inputSampleOffset, p_outputSampleOffset));

	// Return a pointer to the new DiscreteInterface
	return m_vecDiscInterface[id];
}

DiscreteInterface * InterfaceContainer::addDiscreteInterface(const char * p_name, const unsigned int p_inputs, const unsigned int p_outputs, const unsigned int p_states, const unsigned int p_params, const double p_sampleTime)
{
	// Store current size of ip vector
	int id = m_vecDiscInterface.size();

	// Create new ip at position `id'
	m_vecDiscInterface.push_back(new DiscreteInterface(this, p_name, p_inputs, p_outputs, p_states, p_params, p_sampleTime));

	// Return a pointer to the new DiscreteInterface
	return m_vecDiscInterface[id];
}

// Return the total number of inputs.
unsigned int InterfaceContainer::getNumInputs()
{
	// Create and initialise counter
	unsigned int counter = 0;

	// Count up total of required inputs for continuous interfaces
	for (int i = 0; i < m_vecContInterface.size(); i++)
	{
		counter += m_vecContInterface[i]->getNumInputs();
	}

	// And now do the same for discrete interfaces
	for (int i = 0; i < m_vecDiscInterface.size(); i++)
	{
		counter += m_vecDiscInterface[i]->getNumInputs();
	}

	return counter;
}

// Return the number of input ports for one interface.
unsigned int InterfaceContainer::getNumInputs(const unsigned int interfaceIndex)
{
	unsigned int index = interfaceIndex;

	// Interface Ids index continuous interfaces first, then discrete
	if (index < m_vecContInterface.size())
		return m_vecContInterface[index]->getNumInputs();

	index -= m_vecContInterface.size();

	if (index < m_vecDiscInterface.size())
		return m_vecDiscInterface[index]->getNumInputs();

	// We shouldn't get here, throw an exception
	throw Exception("getNumInputs: Index out of range");
}

// Return the total number of input ports with a width > 0.
unsigned int InterfaceContainer::getNumActiveInputPorts()
{
	// Create and initialise counter
	unsigned int counter = 0;

	// Count up total of continuous interfaces with inputs
	for (int i = 0; i < m_vecContInterface.size(); i++)
	{
		if (m_vecContInterface[i]->getNumInputs() > 0)
			counter++;
	}

	// And now do the same for discrete interfaces
	for (int i = 0; i < m_vecDiscInterface.size(); i++)
	{
		if (m_vecDiscInterface[i]->getNumInputs() > 0)
			counter++;
	}

	return counter;
}

// Return the width of the ith active input port.
unsigned int InterfaceContainer::getActiveInputPortWidth(const unsigned int portIndex)
{
	unsigned int index = portIndex;

	// Search through continuous interfaces with inputs
	for (int i = 0; i < m_vecContInterface.size(); i++)
	{
		if (m_vecContInterface[i]->getNumInputs() > 0)
		{
			if (index == 0)
				return m_vecContInterface[i]->getNumInputs();
			index--;
		}
	}

	// And now do the same for discrete interfaces
	for (int i = 0; i < m_vecDiscInterface.size(); i++)
	{
		if (m_vecDiscInterface[i]->getNumInputs() > 0)
			if (index == 0)
				return m_vecDiscInterface[i]->getNumInputs();
			index--;
	}

	// We shouldn't get here, throw an exception
	throw Exception("getActiveInputPortWidth: Index out of range");
}

// Return the total number of output ports.
unsigned int InterfaceContainer::getNumOutputs()
{
	// Create and initialise counter
	unsigned int counter = 0;

	// Count up total of required inputs for continuous interfaces
	for (int i = 0; i < m_vecContInterface.size(); i++)
	{
		counter += m_vecContInterface[i]->getNumOutputs();
	}

	// And now do the same for discrete interfaces
	for (int i = 0; i < m_vecDiscInterface.size(); i++)
	{
		counter += m_vecDiscInterface[i]->getNumOutputs();
	}

	return counter;
}

// Return the number of output ports for one interface.
unsigned int InterfaceContainer::getNumOutputs(const unsigned int interfaceIndex)
{
	unsigned int index = interfaceIndex;

	// Interface Ids index continuous interfaces first, then discrete
	if (index < m_vecContInterface.size())
		return m_vecContInterface[index]->getNumOutputs();

	index -= m_vecContInterface.size();

	if (index < m_vecDiscInterface.size())
		return m_vecDiscInterface[index]->getNumOutputs();

	// We shouldn't get here, throw an exception
	throw Exception("getNumOutputs: Index out of range");
}

// Return the total number of output ports with a width > 0.
unsigned int InterfaceContainer::getNumActiveOutputPorts()
{
	// Create and initialise counter
	unsigned int counter = 0;

	// Count up total of continuous interfaces with outputs
	for (int i = 0; i < m_vecContInterface.size(); i++)
	{
		if (m_vecContInterface[i]->getNumOutputs() > 0)
			counter++;
	}

	// And now do the same for discrete interfaces
	for (int i = 0; i < m_vecDiscInterface.size(); i++)
	{
		if (m_vecDiscInterface[i]->getNumOutputs() > 0)
			counter++;
	}

	return counter;
}

// Return the width of the ith active output port.
unsigned int InterfaceContainer::getActiveOutputPortWidth(const unsigned int portIndex)
{
	unsigned int index = portIndex;

	// Search through continuous interfaces with outputs
	for (int i = 0; i < m_vecContInterface.size(); i++)
	{
		if (m_vecContInterface[i]->getNumOutputs() > 0)
		{
			if (index == 0)
				return m_vecContInterface[i]->getNumOutputs();
			index--;
		}
	}

	// And now do the same for discrete interfaces
	for (int i = 0; i < m_vecDiscInterface.size(); i++)
	{
		if (m_vecDiscInterface[i]->getNumOutputs() > 0)
			if (index == 0)
				return m_vecDiscInterface[i]->getNumOutputs();
			index--;
	}

	// We shouldn't get here, throw an exception
	throw Exception("getActiveOutputPortWidth: Index out of range");
}

// Return the total number of continuous states.
unsigned int InterfaceContainer::getNumContinuousStates()
{
	// Create and initialise counter
	unsigned int counter = 0;

	// Count up total of required states for continuous interfaces
	for (int i = 0; i < m_vecContInterface.size(); i++)
	{
		counter += m_vecContInterface[i]->getNumStates();
	}

	return counter;
}

// Return the number of continuous states for one interface.
unsigned int InterfaceContainer::getNumContinuousStates(const unsigned int interfaceIndex)
{
	// Check index is in range
	if (interfaceIndex >= m_vecContInterface.size())
		throw Exception("getNumContinuousStates: Index out of range");

	return m_vecContInterface[interfaceIndex]->getNumStates();
}

// Return the total number of discrete states.
unsigned int InterfaceContainer::getNumDiscreteStates()
{
	// Create and initialise counter
	unsigned int counter = 0;

	// Count up total of required states for discrete interfaces
	for (int i = 0; i < m_vecDiscInterface.size(); i++)
	{
		counter += m_vecDiscInterface[i]->getNumStates();
	}

	return counter;
}

// Return the number of discrete states for one interface.
unsigned int InterfaceContainer::getNumDiscreteStates(const unsigned int interfaceIndex)
{
	// Check index is in range
	if (interfaceIndex >= m_vecDiscInterface.size())
		throw Exception("getNumDiscreteStates: Index out of range");

	return m_vecDiscInterface[interfaceIndex]->getNumStates();
}

// Return the total number of parameters
unsigned int InterfaceContainer::getNumParams()
{
	// Create and initialise counter
	unsigned int counter = 0;

	// Count up total of required parameters for continuous interfaces
	for (int i = 0; i < m_vecContInterface.size(); i++)
	{
		counter += m_vecContInterface[i]->getNumParams();
	}

	// And now do the same for discrete interfaces
	for (int i = 0; i < m_vecDiscInterface.size(); i++)
	{
		counter += m_vecDiscInterface[i]->getNumParams();
	}

	return counter;
}

// Return the number of parameters for one interface.
unsigned int InterfaceContainer::getNumParams(const unsigned int interfaceIndex)
{
	unsigned int index = interfaceIndex;

	// Interface Ids index continuous interfaces first, then discrete
	if (index < m_vecContInterface.size())
		return m_vecContInterface[index]->getNumParams();

	index -= m_vecContInterface.size();

	if (index < m_vecDiscInterface.size())
		return m_vecDiscInterface[index]->getNumParams();

	// We shouldn't get here, throw an exception
	throw Exception("getNumParams: Index out of range");
}

// Return the total number of parameters with a width > 0.
unsigned int InterfaceContainer::getNumActiveParams()
{
	// Create and initialise counter
	unsigned int counter = 0;

	// Count up total of continuous interfaces with parameters
	for (int i = 0; i < m_vecContInterface.size(); i++)
	{
		if (m_vecContInterface[i]->getNumParams() > 0)
			counter++;
	}

	// And now do the same for discrete interfaces
	for (int i = 0; i < m_vecDiscInterface.size(); i++)
	{
		if (m_vecDiscInterface[i]->getNumParams() > 0)
			counter++;
	}

	return counter;
}

// Return the width of the ith parameter port.
unsigned int InterfaceContainer::getActiveParamWidth(unsigned int portIndex)
{
	unsigned int index = portIndex;

	// Search through continuous interfaces with outputs
	for (int i = 0; i < m_vecContInterface.size(); i++)
	{
		if (m_vecContInterface[i]->getNumParams() > 0)
		{
			if (index == 0)
				return m_vecContInterface[i]->getNumParams();
			index--;
		}
	}

	// And now do the same for discrete interfaces
	for (int i = 0; i < m_vecDiscInterface.size(); i++)
	{
		if (m_vecDiscInterface[i]->getNumParams() > 0)
			if (index == 0)
				return m_vecDiscInterface[i]->getNumParams();
			index--;
	}

	// We shouldn't get here, throw an exception
	throw Exception("getActiveParamWidth: Index out of range");
}

// Return the sample time for a given active input port
double InterfaceContainer::getActiveInputPortSampleTime(const unsigned int portIndex)
{
	unsigned int index = portIndex;

	// Search through continuous interfaces with inputs
	for (int i = 0; i < m_vecContInterface.size(); i++)
	{
		if (m_vecContInterface[i]->getNumInputs() > 0)
		{
			if (index == 0)
				return SAMPLE_TIME_CONTINUOUS;
			index--;
		}
	}

	// And now do the same for discrete interfaces
	for (int i = 0; i < m_vecDiscInterface.size(); i++)
	{
		if (m_vecDiscInterface[i]->getNumInputs() > 0)
			if (index == 0)
				return m_vecDiscInterface[i]->getInputSampleTime();
			index--;
	}

	// We shouldn't get here, throw an exception
	throw Exception("getActiveInputPortSampleTime: Index out of range");
}

// Return the sample time offset for a given active input port
double InterfaceContainer::getActiveInputPortSampleOffset(const unsigned int portIndex)
{
	unsigned int index = portIndex;

	// Search through continuous interfaces with inputs
	for (int i = 0; i < m_vecContInterface.size(); i++)
	{
		if (m_vecContInterface[i]->getNumInputs() > 0)
		{
			if (index == 0)
				return SAMPLE_OFFSET_CONTINUOUS;
			index--;
		}
	}

	// And now do the same for discrete interfaces
	for (int i = 0; i < m_vecDiscInterface.size(); i++)
	{
		if (m_vecDiscInterface[i]->getNumInputs() > 0)
			if (index == 0)
				return m_vecDiscInterface[i]->getInputSampleOffset();
			index--;
	}

	// We shouldn't get here, throw an exception
	throw Exception("getActiveInputPortSampleOffset: Index out of range");
}

// Return the sample time for a given active output port
double InterfaceContainer::getActiveOutputPortSampleTime(const unsigned int portIndex)
{
	unsigned int index = portIndex;

	// Search through continuous interfaces with outputs
	for (int i = 0; i < m_vecContInterface.size(); i++)
	{
		if (m_vecContInterface[i]->getNumOutputs() > 0)
		{
			if (index == 0)
				return SAMPLE_TIME_CONTINUOUS;
			index--;
		}
	}

	// And now do the same for discrete interfaces
	for (int i = 0; i < m_vecDiscInterface.size(); i++)
	{
		if (m_vecDiscInterface[i]->getNumOutputs() > 0)
			if (index == 0)
				return m_vecDiscInterface[i]->getOutputSampleTime();
			index--;
	}

	// We shouldn't get here, throw an exception
	throw Exception("getActiveOutputPortSampleTime: Index out of range");
}

// Return the sample time offset for a given active output port
double InterfaceContainer::getActiveOutputPortSampleOffset(const unsigned int portIndex)
{
	unsigned int index = portIndex;

	// Search through continuous interfaces with outputs
	for (int i = 0; i < m_vecContInterface.size(); i++)
	{
		if (m_vecContInterface[i]->getNumOutputs() > 0)
		{
			if (index == 0)
				return SAMPLE_OFFSET_CONTINUOUS;
			index--;
		}
	}

	// And now do the same for discrete interfaces
	for (int i = 0; i < m_vecDiscInterface.size(); i++)
	{
		if (m_vecDiscInterface[i]->getNumOutputs() > 0)
			if (index == 0)
				return m_vecDiscInterface[i]->getOutputSampleOffset();
			index--;
	}

	// We shouldn't get here, throw an exception
	throw Exception("getActiveOutputPortSampleOffset: Index out of range");
}

// Prints an Interface map for all interfaces
void InterfaceContainer::printInfo()
{

	printf("\n---------------------------------------InterfaceContainer-------------------------------------------\n");
	printf("Summary:\n----------\n");
	printf("Inputs: \t%d\n",getNumInputs());
	printf("Outputs:\t%d\n",getNumOutputs());
	printf("States: \t%d (Continuous)\n",getNumContinuousStates());
	printf("States: \t%d (Discrete)\n",getNumDiscreteStates());
	printf("Params: \t%d\n",getNumParams());
	printf("\n\n");

	printf("Port map (Inputs):\n");
	for (int i = 0; i < m_vecContInterface.size(); i++)
		printf("[%s]:\t%d\n", m_vecContInterface[i]->getName().c_str(), m_vecContInterface[i]->getNumInputs());
	for (int i = 0; i < m_vecDiscInterface.size(); i++)
		printf("[%s]:\t%d\n", m_vecDiscInterface[i]->getName().c_str(), m_vecDiscInterface[i]->getNumInputs());
	printf("\n\n");

	printf("Port map (Outputs):\n");
	for (int i = 0; i < m_vecContInterface.size(); i++)
		printf("[%s]:\t%d\n", m_vecContInterface[i]->getName().c_str(), m_vecContInterface[i]->getNumOutputs());
	for (int i = 0; i < m_vecDiscInterface.size(); i++)
		printf("[%s]:\t%d\n", m_vecDiscInterface[i]->getName().c_str(), m_vecDiscInterface[i]->getNumOutputs());
	printf("\n\n");

	if (m_vecContInterface.size() > 0)
	{
		printf("Port map (Continuous States):\n");
		for (int i = 0; i < m_vecContInterface.size(); i++)
			printf("[%s]:\t%d\n", m_vecContInterface[i]->getName().c_str(), m_vecContInterface[i]->getNumStates());
		printf("\n\n");
	}

	if (m_vecDiscInterface.size() > 0)
	{
		printf("Port map (Discrete States):\n");
		for (int i = 0; i < m_vecDiscInterface.size(); i++)
			printf("[%s]:\t%d\n", m_vecDiscInterface[i]->getName().c_str(), m_vecDiscInterface[i]->getNumStates());
		printf("\n\n");
	}

	printf("Port map (Params):\n");
	for (int i = 0; i < m_vecContInterface.size(); i++)
		printf("[%s]:\t%d\n", m_vecContInterface[i]->getName().c_str(), m_vecContInterface[i]->getNumParams());
	for (int i = 0; i < m_vecDiscInterface.size(); i++)
		printf("[%s]:\t%d\n", m_vecDiscInterface[i]->getName().c_str(), m_vecDiscInterface[i]->getNumParams());
	printf("\n\n");

	printf("\n");
	printf("---------------------------------------/InterfaceContainer------------------------------------------\n");
}

// Get a pointer to the input data for a particular Interface.
//
// \param interface Pointer to the Interface
// \return A pointer to the data array
const real_T * InterfaceContainer::getU(Interface * interface)
{
	// Create and initialise counter
	unsigned int counter = 0;

	// Count up total of required inputs for continuous interfaces
	// Until we reach our interface
	for (int i = 0; i < m_vecContInterface.size(); i++)
	{
		if (m_vecContInterface[i]->getNumInputs() > 0)
		{
			if (m_vecContInterface[i] == (ContinuousInterface*)interface)
			{
				return (const real_T *) ssGetInputPortRealSignalPtrs(m_sim->getS(), counter);
			}
			counter++;
		}
	}

	// And now do the same for discrete interfaces
	for (int i = 0; i < m_vecDiscInterface.size(); i++)
	{
		if (m_vecDiscInterface[i]->getNumInputs() > 0)
		{
			if (m_vecDiscInterface[i] == (DiscreteInterface*)interface)
			{
				return (const real_T *)ssGetInputPortRealSignalPtrs(m_sim->getS(), counter);
			}
			counter++;
		}
	}

	// Should never get here
	throw Exception("getU: Invalid interface pointer");
}

// Get a pointer to the ouput data for a particular Interface.
//
// \param interface Pointer to the Interface
// \return A pointer to the data array
real_T * InterfaceContainer::getY(Interface * interface)
{
	// Create and initialise counter
	unsigned int counter = 0;

	// Count up total of required outputs for continuous interfaces
	// Until we reach our interface
	for (int i = 0; i < m_vecContInterface.size(); i++)
	{
		if (m_vecContInterface[i]->getNumOutputs() > 0)
		{
			if (m_vecContInterface[i] == (ContinuousInterface*)interface)
			{
				return ssGetOutputPortRealSignal(m_sim->getS(), counter);
			}
			counter++;
		}
	}

	// And now do the same for discrete interfaces
	for (int i = 0; i < m_vecDiscInterface.size(); i++)
	{
		if (m_vecDiscInterface[i]->getNumOutputs() > 0)
		{
			if (m_vecDiscInterface[i] == (DiscreteInterface*)interface)
			{
				return ssGetOutputPortRealSignal(m_sim->getS(), counter);
			}
			counter++;
		}
	}

	// Should never get here
	throw Exception("getY: Invalid interface pointer");
}

// Get a pointer to the state data for a particular ContinuousInterface.
//
// \param interface Pointer to the Interface
// \return A pointer to the data array
real_T * InterfaceContainer::getContinuousX(ContinuousInterface * interface)
{
	// Create and initialise counter
	unsigned int counter = 0;

	// Count up total of required outputs for continuous interfaces
	// Until we reach our interface
	for (int i = 0; i < m_vecContInterface.size(); i++)
	{
		if (m_vecContInterface[i] == interface)
		{
			return &ssGetContStates(m_sim->getS())[counter];
		}
		counter += m_vecContInterface[i]->getNumStates();
	}

	// Should never get here
	throw Exception("getContinuousX: Invalid interface pointer");
}

// Get a pointer to the state data for a particular DiscreteInterface.
//
// \param interface Pointer to the Interface
// \return A pointer to the data array
real_T * InterfaceContainer::getDiscreteX(DiscreteInterface * interface)
{
	// Create and initialise counter
	unsigned int counter = 0;

	// Count up total of required outputs for discrete interfaces
	// Until we reach our interface
	for (int i = 0; i < m_vecDiscInterface.size(); i++)
	{
		if (m_vecDiscInterface[i] == interface)
		{
			return &ssGetDiscStates(m_sim->getS())[counter];
		}
		counter += m_vecDiscInterface[i]->getNumStates();
	}

	// Should never get here
	throw Exception("getDiscreteX: Invalid interface pointer");
}

// Get a pointer to the state derivative data for a particular ContinuousInterface.
//
// \param interface Pointer to the Interface
// \return A pointer to the data array
real_T * InterfaceContainer::getDx(ContinuousInterface * interface)
{
	// Create and initialise counter
	unsigned int counter = 0;

	// Count up total of required outputs for continuous interfaces
	// Until we reach our interface
	for (int i = 0; i < m_vecContInterface.size(); i++)
	{
		if (m_vecContInterface[i] == interface)
		{
			return &ssGetdX(m_sim->getS())[counter];
		}
		counter += m_vecContInterface[i]->getNumStates();
	}

	// Should never get here
	throw Exception("getDx: Invalid interface pointer");
}

// Get a pointer to the simulation parameters data for a particular Interface.
//
// \param interface Pointer to the Interface
// \return A pointer to the data array
const real_T * InterfaceContainer::getParam(Interface * interface)
{
	// Create and initialise counter
	unsigned int counter = 0;

	// Count up total of required parameters for continuous interfaces
	// Until we reach our interface
	for (int i = 0; i < m_vecContInterface.size(); i++)
	{
		if (m_vecContInterface[i] == (ContinuousInterface*)interface)
		{
			return &mxGetPr(ssGetSFcnParam(m_sim->getS(),0))[counter];
		}
		counter += m_vecContInterface[i]->getNumParams();
	}

	// And now do the same for discrete interfaces
	for (int i = 0; i < m_vecDiscInterface.size(); i++)
	{
		if (m_vecDiscInterface[i] == (DiscreteInterface*)interface)
		{
			return &mxGetPr(ssGetSFcnParam(m_sim->getS(),0))[counter];
		}
		counter += m_vecDiscInterface[i]->getNumParams();
	}

	// Should never get here
	throw Exception("getParam: Invalid interface pointer");
}

// Invalidate the input pointer for all Interfaces
void InterfaceContainer::invalidateU()
{
	// Invalidate input pointer for all continuous interfaces
	for (int i = 0; i < m_vecContInterface.size(); i++)
	{
		m_vecContInterface[i]->invalidateU();
	}

	// And now do the same for discrete interfaces
	for (int i = 0; i < m_vecDiscInterface.size(); i++)
	{
		m_vecDiscInterface[i]->invalidateU();
	}
}

// Invalidate the output pointer for all Interfaces
void InterfaceContainer::invalidateY()
{
	// Invalidate output pointer for all continuous interfaces
	for (int i = 0; i < m_vecContInterface.size(); i++)
	{
		m_vecContInterface[i]->invalidateY();
	}

	// And now do the same for discrete interfaces
	for (int i = 0; i < m_vecDiscInterface.size(); i++)
	{
		m_vecDiscInterface[i]->invalidateY();
	}
}

// Invalidate the state pointer for all Interfaces
void InterfaceContainer::invalidateX()
{
	// Invalidate state pointer for all continuous interfaces
	for (int i = 0; i < m_vecContInterface.size(); i++)
	{
		m_vecContInterface[i]->invalidateX();
	}

	// And now do the same for discrete interfaces
	for (int i = 0; i < m_vecDiscInterface.size(); i++)
	{
		m_vecDiscInterface[i]->invalidateX();
	}
}

// Invalidate the state derivative pointer for all ContinuousInterfaces
void InterfaceContainer::invalidateDx()
{
	// Invalidate state derivative pointer for all continuous interfaces
	for (int i = 0; i < m_vecContInterface.size(); i++)
	{
		m_vecContInterface[i]->invalidateDx();
	}
}

// Invalidate the parameter pointer for all Interfaces
void InterfaceContainer::invalidateParam()
{
	// Invalidate parameter pointer for all continuous interfaces
	for (int i = 0; i < m_vecContInterface.size(); i++)
	{
		m_vecContInterface[i]->invalidateParam();
	}

	// And now do the same for discrete interfaces
	for (int i = 0; i < m_vecDiscInterface.size(); i++)
	{
		m_vecDiscInterface[i]->invalidateParam();
	}
}

// Invalidate all pointers for all Interfaces
void InterfaceContainer::invalidateAll()
{
	// Invalidate all pointers for all continuous interfaces
	for (int i = 0; i < m_vecContInterface.size(); i++)
	{
		m_vecContInterface[i]->invalidateU();
		m_vecContInterface[i]->invalidateY();
		m_vecContInterface[i]->invalidateX();
		m_vecContInterface[i]->invalidateDx();
		m_vecContInterface[i]->invalidateParam();
	}

	// And now do the same for discrete interfaces
	for (int i = 0; i < m_vecDiscInterface.size(); i++)
	{
		m_vecDiscInterface[i]->invalidateU();
		m_vecDiscInterface[i]->invalidateY();
		m_vecDiscInterface[i]->invalidateX();
		m_vecDiscInterface[i]->invalidateParam();
	}
}
