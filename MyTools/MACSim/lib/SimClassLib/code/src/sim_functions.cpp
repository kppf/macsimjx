#include "../include/sim.h"

#ifdef __cplusplus
extern "C" { // use the C fcn-call standard for all functions
#endif       // defined within this scope



// *8*

	/*====================*
	 * S-function methods *
	 *====================*/

	/* Function: SimInitializeSizes ===============================================
	 * Abstract:
	 *    The sizes information is used by Simulink to determine the S-function
	 *    block's characteristics (number of inputs, outputs, states, etc.).
	 */
	void SimInitializeSizes(SimStruct * S, Sim * sim_temp)
	{
		// Counter and time variable
		int i;
		double n;

		// Print Io map
		sim_temp->getInterfaceContainer()->printInfo();

		// Set up the number of continuous and discrete states from temp_sim
		ssSetNumContStates(S, sim_temp->getInterfaceContainer()->getNumContinuousStates());
		ssSetNumDiscStates(S, sim_temp->getInterfaceContainer()->getNumDiscreteStates());

		// We will used port-based sample times to allow hybrid flexibility
		ssSetNumSampleTimes(S, PORT_BASED_SAMPLE_TIMES);
		
		// Set up the width of the (actice) input ports from temp_sim
		// Also set up sample times and offsets for active ports
		for(i=0;i<sim_temp->getInterfaceContainer()->getNumActiveInputPorts();i++)
		{
			ssSetInputPortWidth(S, i, sim_temp->getInterfaceContainer()->getActiveInputPortWidth(i));
			ssSetInputPortDirectFeedThrough(S, i, 1);
			
			// Set up sample time and offset
			n = sim_temp->getInterfaceContainer()->getActiveInputPortSampleTime(i);
			if (n == InterfaceContainer::SAMPLE_TIME_CONTINUOUS)
			{
				ssSetInputPortSampleTime(S, i, CONTINUOUS_SAMPLE_TIME);
				ssSetInputPortOffsetTime(S, i, 0.0);
			}
			else
			{
				ssSetInputPortSampleTime(S, i, n);
				ssSetInputPortOffsetTime(S, i, sim_temp->getInterfaceContainer()->getActiveInputPortSampleOffset(i));
			}
		}

		// Set up the width of the (actice) output ports from temp_sim
		// Also set up sample times and offsets for active ports
		for(i=0;i<sim_temp->getInterfaceContainer()->getNumActiveOutputPorts();i++)
		{
			ssSetOutputPortWidth(S, i, sim_temp->getInterfaceContainer()->getActiveOutputPortWidth(i));
			
			// Set up sample time and offset
			n = sim_temp->getInterfaceContainer()->getActiveOutputPortSampleTime(i);
			if (n == InterfaceContainer::SAMPLE_TIME_CONTINUOUS)
			{
				ssSetOutputPortSampleTime(S, i, CONTINUOUS_SAMPLE_TIME);
				ssSetOutputPortOffsetTime(S, i, 0.0);
			}
			else
			{
				ssSetOutputPortSampleTime(S, i, n);
				ssSetOutputPortOffsetTime(S, i, sim_temp->getInterfaceContainer()->getActiveOutputPortSampleOffset(i));
			}
		}

		// Set up the number of parameters
		ssSetNumSFcnParams(S, sim_temp->getInterfaceContainer()->getNumActiveParams());  //Number of expected parameters
		ssSetNumSFcnParams(S, 0);  //Number of expected parameters
		if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
			return; // Parameter mismatch will be reported by Simulink
		}

		// Take care when specifying exception free code - see sfuntmpl.doc
		#ifdef SIM_EXCEPTION_FREE_CODE
			ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);
		#endif
		
		ssSetNumRWork(S, 0);
		ssSetNumIWork(S, 0);
		ssSetNumPWork(S, 1); // reserve element in the pointers vector to store a C++ object
		ssSetNumModes(S, 0);
		ssSetNumNonsampledZCs(S, 0);
	}


	/* Function: SimInitializeSampleTimes =========================================
	 * Abstract:
	 *    This function is used to specify the sample time(s) for your
	 *    S-function. You must register the same number of sample times as
	 *    specified in ssSetNumSampleTimes.
	 */
	void SimInitializeSampleTimes(SimStruct *S)
	{
		// Not required, we're using port based sample times
	}

	#define Sim_START  /* Change to #undef to remove function */
	#if defined(Sim_START)
	  /* Function: SimStart =======================================================
	   * Abstract:
	   *    This function is called once at start of model execution. If you
	   *    have states that should be initialized once, this is the place
	   *    to do it.
	   */
	  void SimStart(SimStruct *S)
	  {
		  //printf("---SimStart---\n");

		Sim *sim = createSim(S);   		 // create new sim object
		ssGetPWork(S)[0] = (void *) sim; // store new C++ object in the pointers vector

		try
		{
			sim->start();
		}
		catch(Exception e)
		{
			e.kill(S);
			return;
		}
	  }
	#endif /*  Sim_START */


	#define Sim_INITIALIZE_CONDITIONS   /* Change to #undef to remove function */
	#if defined(Sim_INITIALIZE_CONDITIONS)
	  /* Function: SimInitializeConditions ========================================
	   * Abstract:
	   *    In this function, you should initialize the continuous and discrete
	   *    states for your S-function block.  The initial states are placed
	   *    in the state vector, ssGetContStates(S) or ssGetRealDiscStates(S).
	   *    You can also perform any other initialization activities that your
	   *    S-function may require. Note, this routine will be called at the
	   *    start of simulation and if it is present in an enabled subsystem
	   *    configured to reset states, it will be call when the enabled subsystem
	   *    restarts execution to reset the states.
	   */
	  void SimInitializeConditions(SimStruct *S)
	  {
		Sim *sim = (Sim *) ssGetPWork(S)[0];   		// retrieve C++ object from the pointers vector and use member functions of the object

		try
		{
			sim->init_cond();
		}
		catch(Exception e)
		{
			e.kill(S);
			return;
		}
	  }
	#endif /* Sim_INITIALIZE_CONDITIONS */



	#define Sim_UPDATE  /* Change to #undef to remove function */
	#if defined(Sim_UPDATE)
	  /* Function: SimUpdate ======================================================
	   * Abstract:
	   *    This function is called once for every major integration time step.
	   *    Discrete states are typically updated here, but this function is useful
	   *    for performing any tasks that should only take place once per
	   *    integration step.
	   */
	  void SimUpdate(SimStruct *S, int_T tid)
	  {
		Sim *sim = (Sim *) ssGetPWork(S)[0];   		// retrieve C++ object from the pointers vector and use member functions of the object

		try
		{
			// Invalidate the u pointers so they will be updated.
			sim->getInterfaceContainer()->invalidateU();

			sim->update();
		}
		catch(Exception e)
		{
			e.kill(S);
			return;
		}
	  }
	#endif /* Sim_UPDATE */



	#define Sim_DERIVATIVES  /* Change to #undef to remove function */
	#if defined(Sim_DERIVATIVES)
	  /* Function: SimDerivatives =================================================
	   * Abstract:
	   *    In this function, you compute the S-function block's derivatives.
	   *    The derivatives are placed in the derivative vector, ssGetdX(S).
	   */
	  void SimDerivatives(SimStruct *S)
	  {
		Sim *sim = (Sim *) ssGetPWork(S)[0];   		// retrieve C++ object from the pointers vector and use member functions of the object

		try
		{
			// Invalidate the dx pointers so they will be updated.
			sim->getInterfaceContainer()->invalidateDx();

			sim->derivative();
		}
		catch(Exception e)
		{
			e.kill(S);
			return;
		}
	  }
	#endif /* Sim_DERIVATIVES */

	/* Function: SimOutputs =======================================================
	 * Abstract:
	 *    In this function, you compute the outputs of your S-function
	 *    block. Generally outputs are placed in the output vector, ssGetY(S).
	 */
	void SimOutputs(SimStruct *S, int_T tid)
	{
		Sim *sim = (Sim *) ssGetPWork(S)[0];   		// retrieve C++ object from the pointers vector and use member functions of the object

		try
		{
			sim->output();
		}
		catch(Exception e)
		{
			e.kill(S);
			return;
		}
	}

	/* Function: SimTerminate =====================================================
	 * Abstract:
	 *    In this function, you should perform any actions that are necessary
	 *    at the termination of a simulation.  For example, if memory was
	 *    allocated in SimStart, this is the place to free it.
	 */
	void SimTerminate(SimStruct *S)
	{
		Sim *sim = (Sim *) ssGetPWork(S)[0]; 		// retrieve C++ object from the pointers vector

		try
		{
			sim->terminate();
		}
		catch(Exception e)
		{
			e.kill(S);
			return;
		}

		delete sim;									// Delete C++ object
	}

	/*========================================================*
	 * See sfuntmpl_doc.c for the optional S-function methods *
	 *========================================================*/

#ifdef __cplusplus
} // end of extern "C" scope
#endif