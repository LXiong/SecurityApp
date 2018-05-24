cmake_minimum_required(VERSION 3.4.1)

# 设置 JNI_DIR 全局目录引用
set(JNI_DIR  ${CMAKE_SOURCE_DIR}/src/main/cpp)

# 添加链接库头文件
include_directories( ${JNI_DIR})

add_library( Secure-lib
             SHARED
             ${JNI_DIR}/Util.cpp
             ${JNI_DIR}/DeviceInfo.cpp
             ${JNI_DIR}/PkgSign.cpp
             ${JNI_DIR}/Analysis.cpp
             ${JNI_DIR}/Syscalls.cpp
             ${JNI_DIR}/SimulatorDetected.cpp
             ${JNI_DIR}/MultiOpenDetected.cpp
             ${JNI_DIR}/InjectDetected.cpp
             ${JNI_DIR}/VaDetected.cpp
             ${JNI_DIR}/SecureApi.cpp)


find_library( log-lib
              log )

target_link_libraries( Secure-lib
                       ${log-lib} )