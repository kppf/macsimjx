//----------------------------------------------------------------------------
// ServerUtil.h
//
// Project : Multi-Agent Control in a Simulink block
// File    : Native code utility function prototypes
//
// Version : 1.0
// Date    : 16th February 2005
// Author  : Peter Mendham
//
// (c) University of York
//----------------------------------------------------------------------------

#ifndef __SERVERUTIL_H__
#define __SERVERUTIL_H__

void setNames(JNIEnv *jenv, jobject jobjThis, const char* name, const char* pipeName);
jint callIntInterfaceMethod(JNIEnv *jenv, jobject jobjThis, const char* methodName);

#endif // __SERVERUTIL_H__