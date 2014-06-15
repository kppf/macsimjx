//==================================================
//    Example SimClassLib file: sim_example2.cpp
//    ------------------------------------------
//
// Description: This example file will perform a
//   state-space simulation on a system with 2
//   inputs, 2 outputs and 3 states. The state
//   matrices are filled with ramdom (but stable!)
//   numbers.  This is example is a discrete time
//   system.
//
// Compilation:
//   Type:
//      >> comp2
//
// To run:
//   Type:
//      >> example2
//
//


// Compulsary Defines
#define SIM_CLASS_NAME 	ExampleClass
#define SIM_FILE_NAME 	sim_example2

//--------------------------------------------------
//            Declare the Sim class
//--------------------------------------------------

#define SIM_CLASS_DECLARATION
#include "sim.h"

class ExampleClass : public Sim
{
	private:
		// Interface
		DiscreteInterface * m_if;

		// Matrices
		SquareMatrix A, D;
		Matrix B, C;


	public:
		// Constructor
		ExampleClass(SimStruct *s);
		// Destructor
		~ExampleClass();

		// Declare Sim Functions
		virtual void start();
		virtual void init_cond();
		virtual void update();
		virtual void derivative();
		virtual void output();
		virtual void terminate();

};


//--------------------------------------------------
//            Define the Sim class
//--------------------------------------------------

#define SIM_CLASS_DEFINITION
#include "sim.h"

// Constructor
ExampleClass::ExampleClass(SimStruct *p_S) : Sim(p_S)
{
	// Register a new Interface which has
	// 2 inputs, 2 outputs, 3 states and 0 parameters, 1ms sample time
	m_if = addDiscreteInterface("My Interface", 2, 2, 3, 0, 0.001);
}

// Destructor
ExampleClass::~ExampleClass()
{
}

// Empty start function
void ExampleClass::start()
{
}

void ExampleClass::init_cond()
{

	// Set initial contition of states
	m_if->x.zero();

	// Configure matrix sizes
	A.resize(3);
	B.resize(3,2);
	C.resize(2,3);
	D.resize(2);

	// Fill matrices with some values...

	// System matrix
	A(0,0) = -0.9851; 	A(0,1) = -0.018; 	A(0,2) = 0.0;
	A(1,0) = 0.001; 	A(1,1) = 1.0; 		A(1,2) = 0.0;
	A(2,0) = 0.0; 		A(2,1) = 0.001; 	A(2,2) = 1.0;

	// Input matrix
	B(0,0) = 0.001; 	B(0,1) = 0.0005;
	B(1,0) = 0.0; 		B(1,1) = 0.0;
	B(2,0) = 0.0; 		B(2,1) = 0.0;

	// Output matrix
	C(0,0) = 8; 	C(0,1) = 1; 	C(0,2) = 0;
	C(1,0) = 4; 	C(1,1) = 5; 	C(1,2) = 0;

	// Direct feed-through matrix
	D(0,0) = -1; 	D(0,1) = -2;
	D(1,0) = -3; 	D(1,1) = -2;
}

void ExampleClass::update()
{
	ColumnVector next_x(m_if->getNumStates());
	
	// x(t+1) = Ax(t) + Bu(t)
	next_x = (A * m_if->x) + (B * m_if->u);
	m_if->x = next_x;
}

void ExampleClass::derivative()
{
}

void ExampleClass::output()
{
	// y(t) = Cx(t) + Du(t)
	m_if->y = (C * m_if->x) + (D * m_if->u);
}

void ExampleClass::terminate()
{
}