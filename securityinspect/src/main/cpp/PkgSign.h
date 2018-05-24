//
// Created by ffthy on 21/11/2017.
//

#include <jni.h>

char* getAppSignSha1(JNIEnv *env, jobject context_object);

char* getAppSignSha1(JNIEnv *env, jobject context_object,jstring pkgname);

jboolean checkValidity(JNIEnv *env, char *Appsha1);
