//! \mainpage The Sim Class Library
//!
//! \section Introduction
//! This class library can be used to help generate S-Function binaries whilst
//! using the C++ language. Although C++ is supported under the \c mex compiler
//! (when used in conjunction with a C++ compiler such as Borland C++ or Microsoft
//! visual C++) the interface is severly bogged down within its original C roots.
//! This class library helps the user `break free' from the ties of the oringinal
//! S-Function C templates.
//!
//! \section Usage
//! \subsection inher_define Inheritance and Definitions
//! The main class is an abstract class called Sim. This class may be inherited from
//! with the user's own simulation class. There are a number of pure virtual member functions
//! which must be overloaded in the user's class to achieve compilation --- these will
//! be discussed later.
//!
//! There are a few #defines that are required at the top of the users class file if the
//! file is to be properly compiled into a usable S-Function. These #defines are:
//!
//! \li \c SIM_CLASS_NAME <\a class_name>
//! \li \c SIM_FILE_NAME <\a file_name (minus extension)>
//! \li \c SIM_CLASS_DECLARATION (to be inserted directly before the class \em declaration)
//! \li \c SIM_CLASS_DEFINITION (to be inserted directly before the class \em definition)
//!
//! The position of the \c SIM_CLASS_DECLARATION and \c SIM_CLASS_DEFINITION defines are very important
//! and it is suggested that they are placed at the top of the cpp file before any other includes.
//! Because of the complicated compilation and linking order that takes place when compiling
//! an S-Function, sim.h has to be included \em twice --- Once before the class \em declaration,
//! and once before the class \em definition(s). It is suggested that a header file is used to
//! abstract the declaration. If this is done then order of instructions will be as shown in the
//! following example:
//!
//! An example of a header file follows:
//!
//! \c example.h:
//! \code
//! #ifndef __EXAMPLE_H__
//! #define __EXAMPLE_H__
//!
//! #include <sim.h>
//!
//!
//! class ExampleClass : public Sim
//! {
//! 	private:
//! 		// Interface Protocal
//! 		ContinuousInterface * m_if;
//!
//! 	public:
//! 		// Constructor
//! 		ExampleClass(SimStruct *s);
//! 		// Destructor
//! 		virtual ~ExampleClass();
//!
//! 		// Declare Sim Functions
//! 		virtual void start();
//! 		virtual void init_cond();
//! 		virtual void update();
//!  		virtual void derivative();
//! 		virtual void output();
//! 		virtual void terminate();
//! };
//!
//! #endif // __EXAMPLE_H__
//! \endcode
//!
//! An example of the code that could define the class in \c example.h follows:
//!
//! \c example.cpp
//! \code
//! //--------------------------------------------------
//! //            Compulsary Defines
//! //--------------------------------------------------
//!
//! #define SIM_CLASS_NAME 	ExampleClass
//! #define SIM_FILE_NAME 	example
//!
//! //--------------------------------------------------
//! //            Declare the Sim class
//! //--------------------------------------------------
//!
//! #define SIM_CLASS_DECLARATION
//! #include "example.h"
//!
//! //--------------------------------------------------
//! //            Define the Sim class
//! //--------------------------------------------------
//!
//! #define SIM_CLASS_DEFINITION
//! #include <sim.h>
//!
//! // Constructor
//! ExampleClass::ExampleClass(SimStruct *p_S) : Sim(p_S)
//! {
//! 	// Register a new Interface with:
//!		// 1 input, 3 outputs and 1 state
//! 	m_if = addContinuousInterface("My Interface", 1, 3, 1, 0);
//! }
//!
//! // Destructor
//! ExampleClass::~ExampleClass()
//! {
//! }
//!
//! void ExampleClass::start()
//! {
//! }
//!
//! void ExampleClass::init_cond()
//! {
//! 	// Set initial contition of state
//! 	m_if->x(0) = 0;
//! }
//!
//! void ExampleClass::update()
//! {
//! }
//!
//! void ExampleClass::derivative()
//! {
//! 	// Put input into dx for integration
//! 	m_if->dx(0) = m_if->u(0);
//! }
//!
//! void ExampleClass::output()
//! {
//! 	// First output a direct copy of input
//! 	m_if->y(0) = m_if->u(0);
//!
//! 	// Second output a multiple of input
//! 	m_if->y(1) = 3 * m_if->u(0);
//!
//! 	// Third output the integral of the input
//! 	m_if->y(2) = m_if->x(0);
//! }
//!
//! void ExampleClass::terminate()
//! {
//! }
//! \endcode
//!
//! Note the use of \c SIM_CLASS_DECLARATION and \c SIM_CLASS_DEFINITION in the above files.
//! After each \c #define is written the \c sim.h file is included. This file must be included after the
//! \c #define commands as it is important for the \c sim.h file to know the circumstance under which it is
//! being included. Note also that the \c SIM_CLASS_DECLARATION \em must be included \em before
//! the \c SIM_CLASS_DEFINITION (although, this is fairly obvious if you think about it!).
//!
//! \subsection ios Inputs and Outputs
//! The ExampleClass above uses 1 input, 3 outputs and 1 state. It obtains these IOs by `requesting'
//! a new `ContinuousInterface' using the command Sim.addContinuousInterface():
//!
//! \code
//! 	m_ip = addContinuousInterface("My Interface", 1, 3, 1, 0); // 1 input, 3 outputs and 1 state
//! \endcode
//!
//! The member variable m_if is a pointer to a ContinuousInterface class. The Sim.addContinuousInterface() function
//! returns a pointer to the newly created interface, and can then be used to access the IOs requested.
//! The ContinuousInterface class has 5 main member functions to access the IOs:
//!
//! \li ContinuousInterface.u(unsigned int index) - To access the inputs
//! \li ContinuousInterface.y(unsigned int index) - To access the outputs
//! \li ContinuousInterface.x(unsigned int index) - To access the states
//! \li ContinuousInterface.dx(unsigned int index) - To access the state derivatives
//! \li ContinuousInterface.param(unsigned int index) - To access the S-Function parameters
//!
//! In the above example, the three outputs are used to output:
//!
//! -# The first output is a direct copy of the input signal.
//! -# The second output is an amplification (by a factor of 3) of the input signal.
//! -# The third output is that of the single state we are using. The state derivative
//!    of which is given by the input in ExampleClass::derivative(). The third output
//!    is therefore the integral of the input.
//!
//! \subsection memb_funcs Compulsary Member Functions
//! There are a number of member functions that are declared as pure virtual in class Sim. These
//! functions will have to defined in the users own simulation class. These functions are:
//!
//! - start()
//! - init_cond()
//! - update()
//! - derivative()
//! - output()
//! - terminate()
//!
//! These functions are designed to mimic the behaviour of thier original S-Function counterparts:
//!
//! - mdlStart()
//! - mdlInitializeConditions()
//! - mdlUpdate()
//! - mdlDerivatives()
//! - mdlOutputs()
//! - mdlTerminate()
//!
//! It is advised that the user reads the documentation in the Matlab literature to obtain an understanding
//! of when these functions are called, and what operations to perform with each function.
//!
//! \section Compilation
//! The code for all the relevant Sim classes are compiled into a library file called \c sim.lib. To compile
//! your code it will need to be linked with \c sim.lib. For example, the \c example.cpp file listed above
//! could be compiled using the following command on the matlab command prompt:
//!
//! \code
//! >> mex example.cpp sim.lib -v
//! \endcode
//!
//! If compilation is successfull an \c example.dll file will be created for use within Simulink.
//!
//! \section installation Installation
//! \subsection matlab5 Installing on MATLAB 5 with Borland 5.x compiler
//! To install the SimClassLib, download the SimClassLib folder to a suitable directory.
//! Then navigate to <tt>\\Documents and Settings\\\<user name\>\\Application Data\\Mathworks\\MATLAB\\</tt>
//! and open <tt>mexopts.bat</tt> in a text editor.
//!
//! Add the line
//! \code
//! set SIMCLASSLIB=<path to SimClassLib\code\>
//! \endcode
//! to the file just under the definition for the MATLAB path. For example:
//! \code
//! rem ********************************************************************
//! rem General parameters
//! rem ********************************************************************
//! set MATLAB=%MATLAB%
//! set BORLAND=c:\Program Files\Borland\BCC55\
//! set SIMCLASSLIB=c:\ltn100\Shared\SimClassLib\
//! ...
//! \endcode
//! On the line beginning <tt>set INCLUDE=...</tt>, add the following to the end:
//! \code
//! ;%SIMCLASSLIB%\code\include
//! \endcode
//! Finally, a bit further down add the following to the end of the line starting <tt>set LINKFLAGS=...</tt>
//! \code
//! -L"%SIMCLASSLIB%\code\bin"
//! \endcode
//! The complete file should look something like this:
//! \code
//! @echo off
//! rem BCC53OPTS.BAT
//! rem
//! rem    Compile and link options used for building MEX-files
//! rem    with the Borland C compiler
//! rem
//! rem    $Revision: 1.2 $  $Date: 1998/12/30 18:59:07 $
//! rem
//! rem ********************************************************************
//! rem General parameters
//! rem ********************************************************************
//! set MATLAB=%MATLAB%
//! set BORLAND=c:\Program Files\Borland\BCC55\
//! set SIMCLASSLIB=c:\ltn100\Shared\SimClassLib\
//! set PATH=%BORLAND%\BIN;%MATLAB_BIN%;%PATH%
//! set INCLUDE=%BORLAND%\INCLUDE;%SIMCLASSLIB%\code\include
//! set LIB=%BORLAND%\LIB;%BORLAND%\LIB\32BIT
//!
//! rem ********************************************************************
//! rem Compiler parameters
//! rem ********************************************************************
//! set COMPILER=bcc32
//! set COMPFLAGS=-c -3 -P- -w- -pc -a8 -I"%INCLUDE%" -DMATLAB_MEX_FILE
//! set OPTIMFLAGS=-O2
//! set DEBUGFLAGS=-v
//! set NAME_OBJECT=-o
//!
//! rem ********************************************************************
//! rem Library creation command
//! rem ********************************************************************
//! set PRELINK_CMDS1=copy "%MATLAB%\extern\include\_mex.def" "%OUTDIR%%MEX_NAME%.def"
//! set PRELINK_CMDS2=implib -i %LIB_NAME%1.lib "%MATLAB%\extern\include\_matlab.def"
//! set PRELINK_CMDS3=implib -i %LIB_NAME%2.lib "%MATLAB%\extern\include\_libmatlbmx.def"
//! set PRELINK_DLLS=implib -i %DLL_NAME%.lib "%MATLAB%\extern\include\_%DLL_NAME%.def"
//!
//! rem ********************************************************************
//! rem Linker parameters
//! rem ********************************************************************
//! set LINKER=perl %MATLAB_BIN%\link_borland_mex.pl
//! set LINKFLAGS=-aa -c -Tpd -x -Gn -L\"%BORLAND%"\lib\32bit .... "%OUTDIR%%MEX_NAME%.def" -L"%SIMCLASSLIB%\code\bin"
//! set LINKOPTIMFLAGS=
//! set LINKDEBUGFLAGS=-v
//! set LINK_FILE=
//! set LINK_LIB=
//! set NAME_OUTPUT="%OUTDIR%%MEX_NAME%".dll
//! set RSP_FILE_INDICATOR=@
//!
//! rem ********************************************************************
//! rem Resource compiler parameters
//! rem ********************************************************************
//! set RC_COMPILER=brcc32 -w32 -D_NO_VCL -fomexversion.res
//! set RC_LINKER=
//! \endcode




//---------------------------------------------------------------------
// Include this bit if sim.h was included BEFORE the class definition
//---------------------------------------------------------------------
#ifdef SIM_CLASS_DECLARATION

	#ifndef __SIM_CLASS_DECLARATION__
	#define __SIM_CLASS_DECLARATION__

		#ifndef SIM_FILE_NAME
			#error SIM_FILE_NAME must be defined!!!
		#endif

		// *1*

		// S_FUNCTION required Defines (required in simulink.c, before simstruct.h)
		#define S_FUNCTION_LEVEL 2
		#define S_FUNCTION_NAME SIM_FILE_NAME

		// *2*
		// Include standard io functions (needed before simstruc.h)
		#include <iostream>

		#ifdef __cplusplus
		extern "C" { // use the C fcn-call standard for all functions
		#endif       // defined within this scope

			// *3*
			#include "simstruc.h"

		#ifdef __cplusplus
		} // end of extern "C" scope
		#endif

		// *4*
		#include "sim_class.h"
		#include "sim_interface_container.h"
		#include "sim_interface.h"
		#include "sim_exception.h"



		// *5*
		// Declare createSim() - defined later
		Sim * createSim(SimStruct *S);


		#ifdef __cplusplus
		extern "C" { // use the C fcn-call standard for all functions
		#endif       // defined within this scope

			// *6*
			#include "sim_functions.h"

			// *7*
			// mdl Functions - Call thier respective Sim Functions

			static void mdlInitializeSizes(SimStruct *S)
			{
				// Create a temporary Sim object to set up port sizes etc...
				Sim * sim_temp = NULL;
				try
				{
					sim_temp = createSim(S);

					// These functions MUST be in the header file, otherwise MATLAB crashes!!!
					if (!ssSetNumInputPorts(S, sim_temp->getInterfaceContainer()->getNumActiveInputPorts())) return;
					if (!ssSetNumOutputPorts(S, sim_temp->getInterfaceContainer()->getNumActiveOutputPorts())) return;

					// Pass temporary Sim object to initialise routine
					SimInitializeSizes(S, sim_temp);
				}
				catch (Exception e)
				{
					e.kill(S);
				}

				// Delete temp Sim object
				if (sim_temp != NULL)
					delete sim_temp;
			}
			static void mdlInitializeSampleTimes(SimStruct *S)
			{
				SimInitializeSampleTimes(S);
			}
			#define MDL_START  // Change to #undef to remove function
			#if defined(MDL_START)
				static void mdlStart(SimStruct *S)
				{
					SimStart(S);
				}
			#endif //  MDL_START
			#define MDL_INITIALIZE_CONDITIONS   // Change to #undef to remove function
			#if defined(MDL_INITIALIZE_CONDITIONS)
				static void mdlInitializeConditions(SimStruct *S)
				{
					SimInitializeConditions(S);
				}
			#endif // MDL_INITIALIZE_CONDITIONS
			#define MDL_UPDATE  // Change to #undef to remove function
			#if defined(MDL_UPDATE)
				static void mdlUpdate(SimStruct *S, int_T tid)
				{
					SimUpdate(S, tid);
				}
			#endif // MDL_UPDATE
			#define MDL_DERIVATIVES  // Change to #undef to remove function
			#if defined(MDL_DERIVATIVES)
				static void mdlDerivatives(SimStruct *S)
				{
					SimDerivatives(S);
				}
			#endif // MDL_DERIVATIVES
			static void mdlOutputs(SimStruct *S, int_T tid)
			{
				SimOutputs(S, tid);
			}
			static void mdlTerminate(SimStruct *S)
			{
				SimTerminate(S);
			}


			// *8*

			/*=============================*
			 * Required S-function trailer *
			 *=============================*/

			#ifdef  MATLAB_MEX_FILE		/* Is this file being compiled as a MEX-file? */
				#include "simulink.c"	/* MEX-file interface mechanism */
			#else
				#include "cg_sfun.h"	/* Code generation registration function */
			#endif

		#ifdef __cplusplus
		} // end of extern "C" scope
		#endif

	#endif // __SIM_CLASS_DECLARATION__
#endif




//---------------------------------------------------------------------
// Include this bit if sim.h was included AFTER the class definition
//---------------------------------------------------------------------

#ifdef SIM_CLASS_DEFINITION
	// If this is after class declaration
	#ifndef __SIM_CLASS_DEFINITION__
	#define __SIM_CLASS_DEFINITION__

		#ifndef SIM_CLASS_DECLARATION
			#error SIM_CLASS_DECLARATION does not exist, or is after SIM_CLASS_DEFINITION !!!
		#endif

		#ifndef SIM_CLASS_NAME
			#error SIM_CLASS_NAME must be defined!!!
		#endif

		// *1*
		// Define custom sim type
		typedef SIM_CLASS_NAME SIM_TYPE;

		// *2*
		//! \fn Sim * createSim(SimStruct *S)
		//! Function used to create a new object of the class inherited from Sim
		//! \param S Pointer to SimStruct
		//! \return Pointer to Sim (polymorphic)
		Sim * createSim(SimStruct *S)
		{
			return new SIM_TYPE(S);
		}


	#endif // __SIM_CLASS_DEFINITION__

#endif // SIM_CLASS_DEFINITION




//----------------------------------------------------------------------------------
// If it was included without SIM_CLASS_DECLARATION or SIM_CLASS_DEFINITION
// then it must just be a normal include, therefore include standard sim headers...
//----------------------------------------------------------------------------------

#ifndef __SIM_CLASS_DECLARATION__
#ifndef __SIM_CLASS_DEFINITION__

	// Normal include, so include some standard headers
	#ifndef __SIM_H__
	#define __SIM_H__

		#include <iostream>
		#include "simstruc.h"
		#include "sim_class.h"
		#include "sim_interface_container.h"
		#include "sim_interface.h"
		#include "sim_exception.h"
		#include "sim_functions.h"
		#include "sim_vector.h"

		// Declare createSim()
		Sim * createSim(SimStruct *S);

	#endif // __SIM_H__

#endif // __SIM_CLASS_DECLARATION__
#endif // __SIM_CLASS_DEFINITION__

