#ifndef __SIM_FUNCTIONS2__
#define __SIM_FUNCTIONS2__

#ifdef __cplusplus
extern "C" { // use the C fcn-call standard for all functions
#endif       // defined within this scope

#include "simstruc.h"

	void SimInitializeSizes(SimStruct *S, Sim * sim_temp);
	void SimInitializeSampleTimes(SimStruct *S);
	void SimStart(SimStruct *S);
	void SimInitializeConditions(SimStruct *S);
	void SimUpdate(SimStruct *S, int_T tid);
	void SimDerivatives(SimStruct *S);
	void SimOutputs(SimStruct *S, int_T tid);
	void SimTerminate(SimStruct *S);

#ifdef __cplusplus
} // end of extern "C" scope
#endif

#endif // __SIM_FUNCTIONS2__