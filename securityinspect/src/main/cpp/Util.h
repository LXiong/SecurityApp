
/**
 * Created by plldzy on 17-11-15.
    基础工具类:
        1)字符串jstring处理；
        2)生成错误信息；
        3)byte数组和char数组转换；
        4)log信息输出
 */
#include <jni.h>


char *jstringToChar(JNIEnv *env, jstring jstr);

jstring charsTojstring(JNIEnv *env, char *str);

jstring getErrorInfo(JNIEnv *env, char *file, const char *func, int line, char *msg);

char *ConvertJByteaArrayToChars(JNIEnv *env, jbyteArray bytearray);

jobject getGlobalContext(JNIEnv *env);

jstring getPackageName(JNIEnv *env, jobject context);

int endsWith(const char *str, const char *suffix);

int startsWith(const char *str, const char *suffix);

char *getProcessName();


