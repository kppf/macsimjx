#include "../include/sim_exception.h"
#include "../include/sim.h"

// Constructor
Exception::Exception() : m_exception_name("General Exception")
{

}

Exception::Exception(const char * p_string) : m_exception_name(p_string)
{

}

// Terminate the S-Function
Exception::kill(SimStruct *p_S)
{
	// Create static array of chars (persistant mem) for error message
	static char msg[512];

	// Create the error message (converting string m_exception_name to char*)
	sprintf(msg,"An exception has occured: %s\n",m_exception_name.c_str());

	// Set the error status
	ssSetErrorStatus(p_S,msg);
}
