#include <jni.h>
#include <string>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include "unistd.h"
#include "SimulatorDetected.h"
#include "PkgSign.h"
#include "SecureApi.h"
#include "InjectDetected.h"
#include "Syscalls.h"
#include "Util.h"
#include "VaDetected.h"
#include "MultiOpenDetected.h"


extern "C"

JNIEXPORT jint JNICALL
Java_com_atomone_Secureinspect_SecureApi_debugCheck(JNIEnv *env, jobject instance) {

    const int BUF_SIZE = 1024;
    char file_path[128] = "\0";
    char buffer[BUF_SIZE] = "\0";

    //获取当前进程的pid
    int pid = getpid();
    sprintf(file_path, "/proc/%d/status", pid);
    FILE *fp = fopen(file_path, "r");
    if (fp == NULL) {
        return -2;
    } else {
        while (fgets(buffer, BUF_SIZE, fp)) {
            if (strncmp(buffer, "TracerPid", 9) == 0) {
                int status = atoi(&buffer[10]);
                if (status != 0) {
                    fclose(fp);
                    return -1;
                }

            }
        }
    }
    return 0;
}

JNIEXPORT jint JNICALL
Java_com_atomone_Secureinspect_SecureApi_rootCheck(JNIEnv *env, jobject instance) {
    int result = 0;
    const char *path[5] = {"/system/bin/su", "/system/xbin/su", "/system/xbin/busybox",
                           "/system/bin/busybox", "/data/local/tmp/busybox"};

    //判断上述文件是否存在并且拥有可执行的权限
    for (int i = 0; i < 5; ++i) {
        if (access(path[i], F_OK | X_OK) == 0) {
            result++;
        }
    }

    return result;
}

JNIEXPORT jint JNICALL
Java_com_atomone_Secureinspect_SecureApi_injectCheck(JNIEnv *env, jobject instance) {
    return getimagebase();
}

JNIEXPORT jint JNICALL
Java_com_atomone_Secureinspect_SecureApi_emulatorCheck(JNIEnv *env, jobject instance,
                                                       jobject context) {
    return simulatorDetected(env, context, 30);
}

JNIEXPORT jint JNICALL
Java_com_atomone_Secureinspect_SecureApi_signPackageCheck(JNIEnv *env, jobject instance,
                                                          jobject context) {

    char *sha1 = getAppSignSha1(env, context);
    jboolean result = checkValidity(env, sha1);
    if (result) {
        return 0;
    } else {
        return 1;
    }

//    jclass verifyListener = env->GetObjectClass(verifyListener_);
//    jmethodID successMethodId = env->GetMethodID(verifyListener, "onVerifySuccess", "()V");
//    jmethodID fialMethodId = env->GetMethodID(verifyListener, "onVerifyFail", "()V");
//
//    if (result) {
//        env->CallVoidMethod(verifyListener_, successMethodId);
//    } else {
//        env->CallVoidMethod(verifyListener_, fialMethodId);
//    }
}

JNIEXPORT jint JNICALL
Java_com_atomone_Secureinspect_SecureApi_isRunInVa(JNIEnv *env, jobject instance) {
    return isRunInVa();
}

JNIEXPORT jint JNICALL
Java_com_atomone_Secureinspect_SecureApi_isMultiOpen(JNIEnv *env, jobject instance) {
    return MultiOpen(env);
}

JNIEXPORT jstring JNICALL
Java_com_atomone_Secureinspect_SecureApi_getRemoteAppSign(JNIEnv *env, jobject instance,
                                                          jobject context, jstring pkgName_) {
    char *sha1 = getAppSignSha1(env, context, pkgName_);
    return charsTojstring(env, sha1);

}