#ifndef __SIM_INTERFACE_H__
#define __SIM_INTERFACE_H__

// Forward define some classes
class InterfaceContainer;

#include <string>
#include <iostream>

#include "simstruc.h"

#include "sim_vector.h"

using namespace std;

//! \brief	Interface class.
//! \author Lee Netherton
//!
//! The Interface class defines an generic interface to Simulink with a number of:
//!
//! \li Inputs. Accessible via u( )
//! \li Outputs. Accessible via y( )
//!	\li States. Accessible via x( )
//! \li Parameters. Accessible via param( )
//!
//! The Interface class is never created, one of its child classes
//! ContinuousInterface or DiscreteInterface is always used
//!
//! \see Sim, InterfaceContainer, ContinuousInterface, DiscreteInterface
//!
class Interface
{
	private:
		//------------------------------------------------------------
		//         Members
		//------------------------------------------------------------

		//! Pointer to InterfaceContainer class.
		InterfaceContainer * m_interfaceContainer;

		//! Name of this interface.
		string m_name;

	public:
		//------------------------------------------------------------
		//         Public Members
		//------------------------------------------------------------

		//! Input vector
		SimInputVector u;

		//! Output vector
		SimOutputVector y;

		//! Parameters vector
		SimParamVector param;

		//------------------------------------------------------------
		//         Constructors
		//------------------------------------------------------------

		//! \brief Constructor for Interface class.
		//!
		//! \param p_interfaceContainer Pointer to the InterfaceContainer class.
		//! \param p_name Name of interface
		//! \param p_inputs Number of inputs required.
		//! \param p_outputs  Number of outputs required.
		//! \param p_params  Number of params required.
		Interface(InterfaceContainer * p_interfaceContainer, const char * p_name, const unsigned int p_inputs, const unsigned int p_outputs, const unsigned int p_params);

		//------------------------------------------------------------
		//         Gets/Sets
		//------------------------------------------------------------

		//! Return the number of inputs for this interface.
		unsigned int getNumInputs() const {return u.getSize();}

		//! Return the number of outputs for this interface.
		unsigned int getNumOutputs() const {return y.getSize();}

		//! Return the number of states for this interface.
		virtual unsigned int getNumStates() const = 0;

		//! Return the number of params for this interface.
		unsigned int getNumParams() const {return param.getSize();}

		//! Returns the InterfaceContainer pointer.
		InterfaceContainer * getInterfaceContainer() {return m_interfaceContainer;}

		//! Returns the interface name.
		string getName() const {return m_name;}

		//------------------------------------------------------------
		//         Other members
		//------------------------------------------------------------

		//! Prints information about the interface.
		virtual void printInfo() const;

		//! Invalidate the input pointer for this Interface
		void invalidateU() {u.invalidate();}

		//! Invalidate the output pointer for this Interface
		void invalidateY() {y.invalidate();}

		//! Invalidate the state pointer for this Interface
		virtual void invalidateX() = 0;

		//! Invalidate the parameter pointer for this Interface
		void invalidateParam() {param.invalidate();}
};

//! \brief	ContinuousInterface class.
//! \author Peter Mendham
//!
//! The ContiuousInterface class extends the Interface class to define an interface
//! to Simulink with a with state derivatives, which are accessible via dx( ).
//!
//! A ContiuousInterface is assumed to require continuous sample time.
//!
//! A new interface protocol can be `requested' via InterfaceContainer.newInterface( ).
//!
//! \see Interface, Sim, InterfaceContainer
//!
class ContinuousInterface : public Interface
{

	public:
		//------------------------------------------------------------
		//         Public Members
		//------------------------------------------------------------

		//! State derivative vector
		SimStateDerivativeVector dx;

		//! State vector
		SimContinuousStateVector x;

		//------------------------------------------------------------
		//         Constructors
		//------------------------------------------------------------

		//! \brief Constructor for ContinuousInterface class.
		//!
		//! \param p_interfaceContainer Pointer to the InterfaceContainer class.
		//! \param p_name Name of interface
		//! \param p_inputs Number of inputs required.
		//! \param p_outputs  Number of outputs required.
		//! \param p_states  Number of states required.
		//! \param p_params  Number of params required.
		ContinuousInterface(InterfaceContainer * p_interfaceContainer, const char * p_name, const unsigned int p_inputs, const unsigned int p_outputs, const unsigned int p_states, const unsigned int p_params);

		//------------------------------------------------------------
		//         Gets/Sets
		//------------------------------------------------------------

		//! Return the number of states for this interface.
		virtual unsigned int getNumStates() const {return x.getSize();}

		//------------------------------------------------------------
		//         Other members
		//------------------------------------------------------------

		//! Invalidate the state pointer for this Interface
		virtual void invalidateX() {x.invalidate();}

		//! Invalidate the state derivative pointer for this Interface
		void invalidateDx() {dx.invalidate();}
};

//! \brief	DiscreteInterface class.
//! \author Peter Mendham
//!
//! The DiscreteInterface class extends the Interface class to define an interface
//! to Simulink with a with next state values, which are accessible via nx( ).
//!
//! A ContiuousInterface is assumed to require continuous sample time.
//!
//! A new interface protocol can be `requested' via InterfaceContainer.newInterface( ).
//!
//! \see Interface, Sim, InterfaceContainer
//!
class DiscreteInterface : public Interface
{

	protected:
		//------------------------------------------------------------
		//         Protected Members
		//------------------------------------------------------------
		double m_inputSampleTime;
		double m_inputSampleOffset;
		double m_outputSampleTime;
		double m_outputSampleOffset;

	public:
		//------------------------------------------------------------
		//         Public Members
		//------------------------------------------------------------

		//! State vector
		SimDiscreteStateVector x;

		//------------------------------------------------------------
		//         Constructors
		//------------------------------------------------------------

		//! \brief Constructor for DiscreteInterface class.
		//!
		//! \param p_interfaceContainer Pointer to the InterfaceContainer class.
		//! \param p_name Name of interface
		//! \param p_inputs Number of inputs required.
		//! \param p_outputs  Number of outputs required.
		//! \param p_states  Number of states required.
		//! \param p_params  Number of params required.
		//! \param p_inputSampleTime  Input sample time in seconds
		//! \param p_outputSampleTime  Output sample time in seconds
		//! \param p_inputSampleOffset  Input sample time offset in seconds
		//! \param p_outputSampleOffset Output sample time offset in seconds
		DiscreteInterface(InterfaceContainer * p_interfaceContainer, const char * p_name, const unsigned int p_inputs, const unsigned int p_outputs, const unsigned int p_states, const unsigned int p_params,
						  const double p_inputSampleTime, const double p_outputSampleTime, const double p_inputSampleOffset, const double p_outputSampleOffset );

		//! \brief Constructor for DiscreteInterface class.
		//!
		//! \param p_interfaceContainer Pointer to the InterfaceContainer class.
		//! \param p_name Name of interface
		//! \param p_inputs Number of inputs required.
		//! \param p_outputs  Number of outputs required.
		//! \param p_states  Number of states required.
		//! \param p_params  Number of params required.
		//! \param p_sampleTime  Input and output sample time in seconds
		DiscreteInterface(InterfaceContainer * p_interfaceContainer, const char * p_name, const unsigned int p_inputs, const unsigned int p_outputs, const unsigned int p_states, const unsigned int p_params, const double p_sampleTime);

		//------------------------------------------------------------
		//         Gets/Sets
		//------------------------------------------------------------

		//! Return the number of states for this interface.
		virtual unsigned int getNumStates() const {return x.getSize();}

		//------------------------------------------------------------
		//         Other members
		//------------------------------------------------------------

		//! Invalidate the state pointer for this Interface
		virtual void invalidateX() {x.invalidate();}

		//! Get the input port sample time in seconds
		double getInputSampleTime() const {return m_inputSampleTime;}

		//! Get the input port sample time offset in seconds
		double getInputSampleOffset() const {return m_inputSampleOffset;}

		//! Get the output port sample time in seconds
		double getOutputSampleTime() const {return m_outputSampleTime;}

		//! Get the output port sample time offset in seconds
		double getOutputSampleOffset() const {return m_outputSampleOffset;}
};

#endif // __SIM_INTERFACE_H__

