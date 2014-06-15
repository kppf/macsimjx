#ifndef __SIM_CLASS_H__
#define __SIM_CLASS_H__

class Interface;
#include "sim_interface_container.h"


//! \brief	Simulation class.
//! \author Lee Netherton
//!
//! The Sim class acts as a continer for the entire simulation. The following functions
//! are called whils the simulation is running:
//! \li \c init_cond( )
//! \li \c update( )
//! \li \c derivative( )
//! \li \c output( )
//! \li \c terminate( )
//! (see inividual functions for their uses)
//!
//! Simulation inputs, ouputs, states, and parameter vectors are accessed via Interface classes.
//! These Interface classes are instantiated and kept in an InterfaceContainer class. New
//! interfaces can be registered with the InterfaceContainer class.
//!
//! The \c Exception class can be used to flag exeptions. The \c Exception::kill() function will
//! stop the simulation and print the exeption that caused it to the screen.
//!
class Sim
{
	private:
		//------------------------------------------------------------
		//         Members
		//------------------------------------------------------------

		//! Pointer to SimStruct structure.
		SimStruct * m_S;

		//! Input/Output member object.
		InterfaceContainer m_interfaceContainer;

	public:
		//------------------------------------------------------------
		//         Constructors
		//------------------------------------------------------------

		//! \brief Sim class constructor.
		//!
		//! \param s Pointer to SimStruct structure (stored in m_S).
		Sim(SimStruct * s);

		//------------------------------------------------------------
		//         Destructor
		//------------------------------------------------------------

		//! \brief Sim class Destructor
		//!
		//! Virtual - the derived class's destructor will always need to be called, as it
		//! may allocate memory.
		virtual ~Sim();

		//------------------------------------------------------------
		//         Pure Virtual Functions
		//------------------------------------------------------------
		virtual void start() = 0;		//!< Used to set up initial conditions.
		virtual void init_cond() = 0;	//!< Used to set up initial conditions.
		virtual void update() = 0;		//!< Called one evey major integration time-step.
		virtual void derivative() = 0;	//!< Used to compute the derivatives witch should be placed in Interface.dx().
		virtual void output() = 0;		//!< Used to send values to S-Function output via Interface.y()
		virtual void terminate() = 0;	//!< Called one at the end of the simulation to initiate any termination routines.

		//------------------------------------------------------------
		//         Gets/Sets
		//------------------------------------------------------------

		//! \brief Get the pointer to the SimStruct.
		//!
		//! \return Pointer to SimStruct
		SimStruct * getS() {return m_S;}

		//! \brief Get a pointer to the InterfaceContainer class object
		//!
		//! \return Pointer to InterfaceContainer object
		InterfaceContainer * getInterfaceContainer() {return &m_interfaceContainer;}

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
		ContinuousInterface * addContinuousInterface(const char * p_name, const unsigned int p_inputs, const unsigned int p_outputs, const unsigned int p_states, const unsigned int p_params)
		{return m_interfaceContainer.addContinuousInterface(p_name, p_inputs, p_outputs, p_states, p_params);}

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
												const double p_inputSampleTime, const double p_outputSampleTime, const double p_inputSampleOffset = 0.0, const double p_outputSampleOffset = 0.0)
		{return m_interfaceContainer.addDiscreteInterface(p_name, p_inputs, p_outputs, p_states, p_params, p_inputSampleTime, p_outputSampleTime, p_inputSampleOffset, p_outputSampleOffset);}

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
		DiscreteInterface * addDiscreteInterface(const char * p_name, const unsigned int p_inputs, const unsigned int p_outputs, const unsigned int p_states, const unsigned int p_params, const double p_sampleTime)
		{return m_interfaceContainer.addDiscreteInterface(p_name, p_inputs, p_outputs, p_states, p_params, p_sampleTime);}

		double getSimTime() const {return ssGetT(m_S);}

		bool runOnce(const double time) const;

		bool runOnce() const {runOnce(0);}
};

#endif // __SIM_CLASS_H__