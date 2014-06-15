//----------------------------------------------------------------------------
// ServerUtil.cpp
//
// Project : Multi-Agent Control in a Simulink block
// File    : Native code utility functions
//
// Version : 1.0
// Date    : 16th February 2005
// Author  : Peter Mendham
//
// (c) University of York
//----------------------------------------------------------------------------

#include <jni.h>

//----------------------------------------------------------------------------
// setNames utility function
//----------------------------------------------------------------------------

void setNames(JNIEnv *jenv, jobject jobjThis, const char* name, const char* pipeName)
{
	jclass jclsThis;
	jfieldID jfid;
	jstring jstr;

	// Get our class
	jclsThis = jenv->GetObjectClass(jobjThis);
	
	// Set server name
	jfid = jenv->GetFieldID(jclsThis, "name", "Ljava/lang/String;");
	jstr = jenv->NewStringUTF(name);
	jenv->SetObjectField(jobjThis, jfid, jstr);

	// Set pipe name
	jfid = jenv->GetFieldID(jclsThis, "pipeName", "Ljava/lang/String;");
	jstr = jenv->NewStringUTF(pipeName);
	jenv->SetObjectField(jobjThis, jfid, jstr);
}

//----------------------------------------------------------------------------
// callIntInterfaceMethod utility function
//----------------------------------------------------------------------------

jint callIntInterfaceMethod(JNIEnv *jenv, jobject jobjThis, const char* methodName)
{
	jclass jclsThis, jclsInterface;
	jobject jobjInterface;
	jfieldID jfid;
	jmethodID jmid;

	// Get our class
	jclsThis = jenv->GetObjectClass(jobjThis);
	
	// Locate interface object
	jfid = jenv->GetFieldID(jclsThis, "callback", "Lmacsim/MACSimServerInterface;");
	jobjInterface = jenv->GetObjectField(jobjThis, jfid);
	jclsInterface = jenv->GetObjectClass(jobjInterface);

	// Collect method ID and call it
	jmid = jenv->GetMethodID(jclsInterface, methodName, "()I");
	return jenv->CallIntMethod(jobjInterface, jmid);
}
