/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class macsim_internal_SimServer */

#ifndef _Included_macsim_internal_SimServer
#define _Included_macsim_internal_SimServer
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     macsim_internal_SimServer
 * Method:    setNameVariables
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_macsim_internal_SimServer_setNameVariables
  (JNIEnv *, jobject);

/*
 * Class:     macsim_internal_SimServer
 * Method:    getInBufferSize
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_macsim_internal_SimServer_getInBufferSize
  (JNIEnv *, jobject);

/*
 * Class:     macsim_internal_SimServer
 * Method:    getOutBufferSize
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_macsim_internal_SimServer_getOutBufferSize
  (JNIEnv *, jobject);

/*
 * Class:     macsim_internal_SimServer
 * Method:    serverFunc
 * Signature: ([B[B)V
 */
JNIEXPORT void JNICALL Java_macsim_internal_SimServer_serverFunc
  (JNIEnv *, jobject, jbyteArray, jbyteArray);

#ifdef __cplusplus
}
#endif
#endif