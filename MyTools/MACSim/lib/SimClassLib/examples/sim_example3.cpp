//--------------------------------------------------
//            Compulsary Defines
//--------------------------------------------------

#define SIM_CLASS_NAME      ExampleClass
#define SIM_FILE_NAME       sim_example3

//--------------------------------------------------
//            Declare the Sim class
//--------------------------------------------------

#define SIM_CLASS_DECLARATION
#include "sim_example3.h"

//--------------------------------------------------
//            Define the Sim class
//--------------------------------------------------

#define SIM_CLASS_DEFINITION
#include <sim.h>

// Constructor
ExampleClass::ExampleClass(SimStruct *p_S) : Sim(p_S)
{
	// Register a new Interface with:
	// 1 input, 3 outputs and 1 state
	m_if = addContinuousInterface("My Interface", 1, 3, 1, 0);
}

// Destructor
ExampleClass::~ExampleClass()
{
}

void ExampleClass::start()
{
}

void ExampleClass::init_cond()
{
	// Set initial contition of state
	m_if->x(0) = 0;
}

void ExampleClass::update()
{
}

void ExampleClass::derivative()
{
	// Put input into dx for integration
	m_if->dx(0) = m_if->u(0);
}

void ExampleClass::output()
{
	// First output a direct copy of input
	m_if->y(0) = m_if->u(0);

	// Second output a multiple of input
	m_if->y(1) = 3 * m_if->u(0);

	// Third output the integral of the input
	m_if->y(2) = m_if->x(0);
}

void ExampleClass::terminate()
{
}