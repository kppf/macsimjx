#ifndef __SIM_INTERFACE_CONTAINER_H__
#define __SIM_INTERFACE_CONTAINER_H__

// Forward define types
class Sim;
//class Interface;
#include "sim_interface.h"

#include <iostream>
#include "vector.h"
#include "simstruc.h"

//! \brief	Simulation interface container class.
//! \author Lee Netherton
//!
//! The InterfaceContainer class acts as a container for all the inputs, outputs, states
//! and parameters for the S-Function. An Interface can be `requested' via the
//! addContinuousInterface() and addDiscreteInterface() member fuctions. Each Interface
//! has its own unique set of IOs which can be accessed as public members of the Interface
//! classes.
//!
class InterfaceContainer
{
	private:
		//------------------------------------------------------------
		//         Members
		//------------------------------------------------------------

		//! Pointer to Sim (owner) class
		Sim * m_sim;

		//! vector< > of ContinuousInterfaces.
		vector<ContinuousInterface *> m_vecContInterface;

		//! vector< > of DiscreteInterfaces.
		vector<DiscreteInterface *> m_vecDiscInterface;

	public:
		//------------------------------------------------------------
		//         Constants
		//------------------------------------------------------------

		static const double SAMPLE_TIME_CONTINUOUS;
		static const double SAMPLE_OFFSET_CONTINUOUS;

		//------------------------------------------------------------
		//         Constructors
		//------------------------------------------------------------

		//! \brief InterfaceContainer constructor
		//!
		//! \param p_sim Pointer to Sim
		InterfaceContainer(Sim *p_sim);

		//------------------------------------------------------------
		//         Destructor
		//------------------------------------------------------------
		virtual ~InterfaceContainer();

		//------------------------------------------------------------
		//         Get/Set
		//------------------------------------------------------------

		//! Return a pointer to the Sim class
		Sim * getSim() const {return m_sim;}

		//------------------------------------------------------------
		//         Other members
		//------------------------------------------------------------

		//! \brief Add a new ContinuousInterface object, and return a
		//! pointer to it
		//!
		//! \param p_name Name of the interface.
		//! \param p_inputs Number of inputs required.
		//! \param p_outputs Number of outputs required.
		//! \param p_states Number of states required.
		//! \param p_params Number of params required.
		//! \return Pointer to ContinuousInterface.
		//! \see ContinuousInterface
		ContinuousInterface * addContinuousInterface(const char * p_name, const unsigned int p_inputs, const unsigned int p_outputs, const unsigned int p_states, const unsigned int p_params);

		//! \brief Add a new DiscreteInterface object, and return a
		//! pointer to it
		//!
		//! \param p_name Name of interface
		//! \param p_inputs Number of inputs required.
		//! \param p_outputs  Number of outputs required.
		//! \param p_states  Number of states required.
		//! \param p_params  Number of params required.
		//! \param p_inputSampleTime  Input sample time in seconds
		//! \param p_outputSampleTime  Output sample time in seconds
		//! \param p_inputSampleOffset  Input sample time offset in seconds
		//! \param p_outputSampleOffset Output sample time offset in seconds
		//! \return Pointer to DiscreteInterface.
		//! \see DiscreteInterface
		DiscreteInterface * addDiscreteInterface(const char * p_name, const unsigned int p_inputs, const unsigned int p_outputs, const unsigned int p_states, const unsigned int p_params,
												const double p_inputSampleTime, const double p_outputSampleTime, const double p_inputSampleOffset, const double p_outputSampleOffset);

		//! \brief Add a new DiscreteInterface object, and return a
		//! pointer to it
		//!
		//! \param p_name Name of interface
		//! \param p_inputs Number of inputs required.
		//! \param p_outputs  Number of outputs required.
		//! \param p_states  Number of states required.
		//! \param p_params  Number of params required.
		//! \param p_sampleTime  Input and output sample time in seconds
		//! \return Pointer to DiscreteInterface.
		//! \see DiscreteInterface
		DiscreteInterface * addDiscreteInterface(const char * p_name, const unsigned int p_inputs, const unsigned int p_outputs, const unsigned int p_states, const unsigned int p_params, const double p_sampleTime);

		//! Return the total number of inputs.
		unsigned int getNumInputs();

		//! Return the number of input ports for one interface.
		unsigned int getNumInputs(const unsigned int interfaceIndex);

		//! Return the total number of input ports with a width > 0.
		unsigned int getNumActiveInputPorts();

		//! Return the width of the ith active input port.
		unsigned int getActiveInputPortWidth(const unsigned int portIndex);

		//! Return the total number of output ports.
		unsigned int getNumOutputs();

		//! Return the number of output ports for one interface.
		unsigned int getNumOutputs(const unsigned int interfaceIndex);

		//! Return the total number of output ports with a width > 0.
		unsigned int getNumActiveOutputPorts();

		//! Return the width of the ith active output port.
		unsigned int getActiveOutputPortWidth(const unsigned int portIndex);

		//! Return the total number of continuous states.
		unsigned int getNumContinuousStates();

		//! Return the number of continuous states for one interface.
		unsigned int getNumContinuousStates(const unsigned int interfaceIndex);

		//! Return the total number of discrete states.
		unsigned int getNumDiscreteStates();

		//! Return the number of discrete states for one interface.
		unsigned int getNumDiscreteStates(const unsigned int interfaceIndex);

		//! Return the total number of parameters.
		unsigned int getNumParams();

		//! Return the number of parameters for one interface.
		unsigned int getNumParams(const unsigned int interfaceIndex);

		//! Return the total number of parameters with a width > 0.
		unsigned int getNumActiveParams();

		//! Return the width of the ith parameter port.
		unsigned int getActiveParamWidth(const unsigned int portIndex);

		//! Return the number of continuous interfaces
		unsigned int getNumContinuousInterfaces() {return m_vecContInterface.size();}

		//! Return the number of discrete interfaces
		unsigned int getNumDiscreteInterfaces() {return m_vecDiscInterface.size();}

		//! Return the total number of interfaces
		unsigned int getNumInterfaces() {return getNumContinuousInterfaces() + getNumDiscreteInterfaces();}

		//! Return the sample time for a given active input port
		double getActiveInputPortSampleTime(const unsigned int portIndex);

		//! Return the sample time offset for a given active input port
		double getActiveInputPortSampleOffset(const unsigned int portIndex);

		//! Return the sample time for a given active output port
		double getActiveOutputPortSampleTime(const unsigned int portIndex);

		//! Return the sample time offset for a given active output port
		double getActiveOutputPortSampleOffset(const unsigned int portIndex);

		//! Prints an Interface map for all interfaces
		void printInfo();

		//! Get a pointer to the input data for a particular Interface.
		//!
		//! \param interface Pointer to the Interface
		//! \return A pointer to the data array
		const real_T * getU(Interface * interface);

		//! Get a pointer to the ouput data for a particular Interface.
		//!
		//! \param interface Pointer to the Interface
		//! \return A pointer to the data array
		real_T * getY(Interface * interface);

		//! Get a pointer to the state data for a particular Interface.
		//!
		//! \param interface Pointer to the Interface
		//! \return A pointer to the data array
		real_T * getContinuousX(ContinuousInterface * interface);

		//! Get a pointer to the state data for a particular Interface.
		//!
		//! \param interface Pointer to the Interface
		//! \return A pointer to the data array
		real_T * getDiscreteX(DiscreteInterface * interface);

		//! Get a pointer to the state derivative data for a particular ContinuousInterface.
		//!
		//! \param interface Pointer to the Interface
		//! \return A pointer to the data array
		real_T * getDx(ContinuousInterface * interface);

		//! Get a pointer to the simulation parameters data for a particular Interface.
		//!
		//! \param interface Pointer to the Interface
		//! \return A pointer to the data array
		const real_T * getParam(Interface * interface);

		//! Invalidate the input pointer for all Interfaces
		void invalidateU();

		//! Invalidate the output pointer for all Interfaces
		void invalidateY();

		//! Invalidate the state pointer for all Interfaces
		void invalidateX();

		//! Invalidate the state derivative pointer for all ContinuousInterfaces
		void invalidateDx();

		//! Invalidate the parameter pointer for all Interfaces
		void invalidateParam();

		//! Invalidate all pointers for all Interfaces
		void invalidateAll();
};

#endif // __SIM_INTERFACE_CONTAINER_H__