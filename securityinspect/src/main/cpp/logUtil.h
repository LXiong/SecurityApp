//
// Created by Administrator on 2018/5/18/018.
//

#ifndef SECURITYAPP_LOGUTIL_H
#define SECURITYAPP_LOGUTIL_H

#endif //SECURITYAPP_LOGUTIL_H
#include <android/log.h>

#define LOG_TAG    "security-sdk-core" // 这个是自定义的LOG的标识
#define LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG, __VA_ARGS__)
#define LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG, __VA_ARGS__)
#define LOGW(...)  __android_log_print(ANDROID_LOG_WARN,LOG_TAG, __VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG, __VA_ARGS__)
#define LOGF(...)  __android_log_print(ANDROID_LOG_FATAL,LOG_TAG, __VA_ARGS__)