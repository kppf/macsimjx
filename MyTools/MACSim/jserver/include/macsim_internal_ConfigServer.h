/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class macsim_internal_ConfigServer */

#ifndef _Included_macsim_internal_ConfigServer
#define _Included_macsim_internal_ConfigServer
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     macsim_internal_ConfigServer
 * Method:    setNameVariables
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_macsim_internal_ConfigServer_setNameVariables
  (JNIEnv *, jobject);

/*
 * Class:     macsim_internal_ConfigServer
 * Method:    getInBufferSize
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_macsim_internal_ConfigServer_getInBufferSize
  (JNIEnv *, jobject);

/*
 * Class:     macsim_internal_ConfigServer
 * Method:    getOutBufferSize
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_macsim_internal_ConfigServer_getOutBufferSize
  (JNIEnv *, jobject);

/*
 * Class:     macsim_internal_ConfigServer
 * Method:    serverFunc
 * Signature: ([B[B)V
 */
JNIEXPORT void JNICALL Java_macsim_internal_ConfigServer_serverFunc
  (JNIEnv *, jobject, jbyteArray, jbyteArray);

#ifdef __cplusplus
}
#endif
#endif
