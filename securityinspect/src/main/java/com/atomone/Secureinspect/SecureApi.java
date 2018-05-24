package com.atomone.Secureinspect;

import android.content.Context;

/**
 * @author Administrator
 */
class SecureApi {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("Secure-lib");
    }

    /**
     * 调试状态检测
     *
     * @return 0 正常 -1 debug -2 无法探测
     */
    public native int debugCheck();

    /**
     * Root检测
     *
     * @return 0 正常  >0 root命令可执行数
     */
    public native int rootCheck();

    /**
     * 注入、hook 检测
     * 例如 Xposed 等
     *
     * @return 0 正常 1 有xposed
     */
    public native int injectCheck();

    /**
     * 模拟器检测
     *
     * @return 1 为 模拟器 -1 为不是模拟器 0 为疑似模拟器
     */
    public native int emulatorCheck(Context mContext);

    /**
     * app签名校验,防止重打包
     *
     * @return 0 正常 1 签名异常
     */
    public native int signPackageCheck(Context mContext);


    /**
     * 是否运行在VirtualApp 中
     *
     * @return 0 正常 >0 环境异常
     */
    public native int isRunInVa();

    /**
     * 是否处于多开环境
     *
     * @return 0 正常 >0 环境异常
     */
    public native int isMultiOpen();


    /**
     * 根据APP的包名获取签名
     *
     * @return 指定app的签名
     */
    public native String getRemoteAppSign(Context mContext, String pkgName);
}
