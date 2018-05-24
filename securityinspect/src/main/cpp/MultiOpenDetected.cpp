//
// Created by Administrator on 2018/5/21/021.
//

#include "MultiOpenDetected.h"
#include "Analysis.h"
#include "Util.h"

int MultiOpen(JNIEnv * env){
    int count = countPathFromUid();
    char *process = getProcessName();
    if (process != NULL) {
        jobject context = getGlobalContext(env);
        jstring pkg = getPackageName(env, context);
        const char *pkgName = env->GetStringUTFChars(pkg, 0);
        if (pkgName != NULL) {
            if (strcmp(process, pkgName) != 0) {
                count++;
            }
        }
        env->DeleteLocalRef(context);
        env->ReleaseStringUTFChars(pkg, pkgName);
        free(process);
    }
    return count;
}