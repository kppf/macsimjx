//----------------------------------------------------------------------------
// ConfigServer.java
//
// Project : Multi-Agent Control in a Simulink block
// File    : Native code for ConfigServer java class
// Package : macsim.internal
//
// Version : 1.0
// Date    : 16th February 2005
// Author  : Peter Mendham
//
// (c) University of York
//----------------------------------------------------------------------------

#include <windows.h>

#include "../include/macsim_internal_ConfigServer.h"
#include "../include/ServerUtil.h"
#include "../../include/interface.h"

//----------------------------------------------------------------------------
// setNameVariables method
//----------------------------------------------------------------------------

JNIEXPORT void JNICALL Java_macsim_internal_ConfigServer_setNameVariables
(JNIEnv *jenv, jobject jobjThis)
{
	setNames(jenv, jobjThis, "configuration", MAC_CONFIG_PIPE_NAME);
}

//----------------------------------------------------------------------------
// getInBufferSize method
//----------------------------------------------------------------------------

JNIEXPORT jint JNICALL Java_macsim_internal_ConfigServer_getInBufferSize
(JNIEnv *jenv, jobject jobjThis)
{
	return (jint)sizeof(DWORD);
}

//----------------------------------------------------------------------------
// getOutBufferSize method
//----------------------------------------------------------------------------

JNIEXPORT jint JNICALL Java_macsim_internal_ConfigServer_getOutBufferSize
(JNIEnv *jenv, jobject jobjThis)
{
	return (jint)sizeof(DWORD);
}

//----------------------------------------------------------------------------
// serverFunc method
//----------------------------------------------------------------------------

JNIEXPORT void JNICALL Java_macsim_internal_ConfigServer_serverFunc
(JNIEnv *jenv, jobject jobjThis, jbyteArray inArray, jbyteArray outArray)
{
	LPDWORD lpdwRequest, lpdwReply;
	
	// Collect pointers to request and reply buffers
	lpdwRequest = (LPDWORD)jenv->GetByteArrayElements(inArray, 0);
	lpdwReply = (LPDWORD)jenv->GetByteArrayElements(outArray, 0);

	// Handle request by calling the interface
	switch (*lpdwRequest) {
	case MAC_CONFIG_CMD_INPUTS:
		*lpdwReply = callIntInterfaceMethod(jenv, jobjThis, "getNumInputs");
		break;

	case MAC_CONFIG_CMD_OUTPUTS:
		*lpdwReply = callIntInterfaceMethod(jenv, jobjThis, "getNumOutputs");
		break;

	case MAC_CONFIG_CMD_SAMPLE:
		*lpdwReply = callIntInterfaceMethod(jenv, jobjThis, "getSampleInterval");
		break;

	default:
		*lpdwReply = MAC_INVALID_RETURN;
	}

	// Release arrays
	jenv->ReleaseByteArrayElements(inArray, (jbyte*)lpdwRequest, 0);
	jenv->ReleaseByteArrayElements(outArray, (jbyte*)lpdwReply, 0);
}
