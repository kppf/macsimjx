#ifndef __EXAMPLE_H__
#define __EXAMPLE_H__

#include <sim.h>


class ExampleClass : public Sim
{
	private:
		// Interface Protocal
		ContinuousInterface * m_if;

	public:
		// Constructor
		ExampleClass(SimStruct *s);
		// Destructor
		virtual ~ExampleClass();

		// Declare Sim Functions
		virtual void start();
		virtual void init_cond();
		virtual void update();
		virtual void derivative();
		virtual void output();
		virtual void terminate();
};

#endif // __EXAMPLE_H__
