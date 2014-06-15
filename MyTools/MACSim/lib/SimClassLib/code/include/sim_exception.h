#ifndef __SIM_EXCEPTION_H__
#define __SIM_EXCEPTION_H__

#include "sim.h"

//! \brief	Exception class.
//! \author Lee Netherton
//!
//! The Exception class is used to throw exceptions which will halt the simulation. For example:
//! \code
//! 	// Check for range error
//! 	if(value<min_range || value>max_range)
//!			throw Exception();
//! \endcode
//! By default Exception class is equiped with a \c string member variable equal to "General Exception".
//! This \c string will be printed when the simulaton halts. To provive a more discriptive exception,
//! the exeption class can be inherited from and then thrown:
//! \code
//! 	class RangeException : Exception
//! 	{
//! 		// Constructor
//! 		RangeException();
//! 	};
//! 	RangeException::RangeException() : m_exception_name("General Exception") {}
//!
//! 	...
//!
//! 	// Check for range error
//! 	if(value<min_range || value>max_range)
//! 		throw RangeException();
//! \endcode
//!
class Exception
{
	protected:
		//! Exception description (defaulted to "General Exception")
		string m_exception_name;

	public:
		//! Exception class constructor.
		Exception();

		//! Class constructor with string input.
		Exception(const char *p_string);

		//! Kill the simulation and print the exception description (m_exception_name) to screen.
		//! \param p_S Pointer to SimStruct.
		kill(SimStruct *p_S);
};

#endif // __SIM_EXCEPTION_H__