/**********************************************************
 *             Class: Sim
 *
 *  Description: C++ class for simulink S-Function.
 *               Requires sim.cpp
 *
 *  Written by Lee Netherton
 *
 **********************************************************/


#include "../include/sim_class.h"

/*==================*
 * Define Sim Class *
 *==================*/

// Constructor
Sim::Sim(SimStruct *p_S) : m_interfaceContainer(this), m_S(p_S)
{
}

// Destructor
Sim::~Sim()
{
}


bool Sim::runOnce(const double time) const
{
	static bool alreadyRun = false;

	if(!alreadyRun)
	{
		alreadyRun = true;

		if(time >= getSimTime())
		{
			return true;
		}
	}

	return false;
}