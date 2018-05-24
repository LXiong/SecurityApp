//
// Created by ffthy on 21/11/2017.
//
#include <cstdio>
#include <unistd.h>
#include <fstream>
#include <string.h>
#include "Util.h"
#include "logUtil.h"
#include "InjectDetected.h"

using namespace std;

/**
 * 存在就是1 不存在就是0
 * @return
 */
int getimagebase() {
    pid_t pid = getpid();
    char fileName[256] = {0};
    sprintf(fileName, "/proc/%d/maps", pid);

    ifstream in(fileName);
    string line;
    char charline[2048] = {0};
    // 有该文件
    if (in) {
        while (getline(in, line)) // line中不包括每行的换行符
        {
            //LOGD(line.data());
//            int length = strlen(line.data());
            strcpy(charline, line.data());
            strtok(charline, "");
            LOGD("data-->%s\n", charline);
//            delete[] charline;

            if (line.find("com.saurik.substrate", 0) != -1 ||
                line.find("XposedBridge.jar", 0) != -1) {
                return 1;
            }
        }
        return 0;
    }

}