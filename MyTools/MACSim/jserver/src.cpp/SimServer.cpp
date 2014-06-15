//----------------------------------------------------------------------------
// SimServer.cpp
//
// Project : Multi-Agent Control in a Simulink block
// File    : Native code for SimServer java class
// Package : macsim.internal
//
// Version : 1.0
// Date    : 16th February 2005
// Author  : Peter Mendham
//
// (c) University of York
//----------------------------------------------------------------------------

#include <windows.h>

#include "../include/macsim_internal_SimServer.h"
#include "../include/ServerUtil.h"
#include "../../include/interface.h"

//----------------------------------------------------------------------------
// setNameVariables method
//----------------------------------------------------------------------------

JNIEXPORT void JNICALL Java_macsim_internal_SimServer_setNameVariables
(JNIEnv *jenv, jobject jobjThis)
{
	setNames(jenv, jobjThis, "simulation", MAC_SIM_PIPE_NAME);
}

//----------------------------------------------------------------------------
// getInBufferSize method
//----------------------------------------------------------------------------

JNIEXPORT jint JNICALL Java_macsim_internal_SimServer_getInBufferSize
(JNIEnv *jenv, jobject jobjThis)
{
	return callIntInterfaceMethod(jenv, jobjThis, "getNumInputs") * sizeof(double);
}

//----------------------------------------------------------------------------
// getOutBufferSize method
//----------------------------------------------------------------------------

JNIEXPORT jint JNICALL Java_macsim_internal_SimServer_getOutBufferSize
(JNIEnv *jenv, jobject jobjThis)
{
	return callIntInterfaceMethod(jenv, jobjThis, "getNumOutputs") * sizeof(double);
}

//----------------------------------------------------------------------------
// serverFunc method
//----------------------------------------------------------------------------

JNIEXPORT void JNICALL Java_macsim_internal_SimServer_serverFunc
(JNIEnv *jenv, jobject jobjThis, jbyteArray inArray, jbyteArray outArray)
{
	jclass jclsThis, jclsInterface;
	jobject jobjInterface;
	jfieldID jfid;
	jmethodID jmid;
	jsize inBuffSize, outBuffSize;
	jbyte *jbRequest, *jbReply;
	jdouble *jdRequest, *jdReply;
	jdoubleArray inArrayD, outArrayD;
	
	// Get our class
	jclsThis = jenv->GetObjectClass(jobjThis);
	
	// Collect sizes of request and reply buffers, in bytes
	inBuffSize = jenv->GetArrayLength(inArray);
	outBuffSize = jenv->GetArrayLength(outArray);
	
	// Create two new double arrays
	inArrayD = jenv->NewDoubleArray(inBuffSize / sizeof(double));
	outArrayD = jenv->NewDoubleArray(outBuffSize / sizeof(double));

	// Collect pointers to request buffers
	jbRequest = jenv->GetByteArrayElements(inArray, 0);
	jdRequest = jenv->GetDoubleArrayElements(inArrayD, 0);
	
	// Copy input memory
	CopyMemory(jdRequest, jbRequest, inBuffSize);
	
	// Release buffers
	jenv->ReleaseByteArrayElements(inArray, jbRequest, 0);
	jenv->ReleaseDoubleArrayElements(inArrayD, jdRequest, 0);

	// Locate interface object
	jfid = jenv->GetFieldID(jclsThis, "callback", "Lmacsim/MACSimServerInterface;");
	jobjInterface = jenv->GetObjectField(jobjThis, jfid);
	jclsInterface = jenv->GetObjectClass(jobjInterface);

	// Call the method and call it
	jmid = jenv->GetMethodID(jclsInterface, "getSimOutputs", "([D[D)V");
	jenv->CallVoidMethod(jobjInterface, jmid, inArrayD, outArrayD);

	// Collect pointers to reply buffers
	jbReply = jenv->GetByteArrayElements(outArray, 0);
	jdReply = jenv->GetDoubleArrayElements(outArrayD, 0);
	
	// Copy output memory
	CopyMemory(jbReply, jdReply, outBuffSize);

	// Release buffers
	jenv->ReleaseByteArrayElements(outArray, jbReply, 0);
	jenv->ReleaseDoubleArrayElements(outArrayD, jdReply, 0);
}