package com.atomone.Secureinspect;

import android.app.ActivityManager;
import android.content.Context;
import android.os.Process;
import android.text.TextUtils;

import java.util.List;

/**
 * @author Administrator
 */
public class SecureSDK {

    private static SecureSDK instance;

    private SecureApi secureApi;

    private SecureSDK() {
        secureApi = new SecureApi();
    }

    public static SecureSDK getInstance() {
        if (null == instance) {
            synchronized (SecureSDK.class) {
                if (null == instance) {
                    instance = new SecureSDK();
                }
            }
        }
        return instance;
    }

    /**
     * 调试状态检测
     *
     * @return ture 调试 false 非调试
     */
    public boolean debugCheck() {
        int debug = secureApi.debugCheck();
        if (debug == -1) {
            return true;
        } else if (debug == 0) {
            return false;
        } else {
            throw new SecureException("debugCheck result" + debug);
        }
    }

    /**
     * root检测
     *
     * @return true 已root false 非root
     */
    public boolean rootCheck() {
        int debug = secureApi.rootCheck();
        if (debug == 0) {
            return false;
        } else {
            return true;
        }
    }


    /**
     * emulator检测
     * * @return  1 为 模拟器 -1 为不是模拟器 0 为疑似模拟器
     *
     * @return
     */
    public boolean emulatorCheck(Context context) {
        int debug = secureApi.emulatorCheck(context);
        if (debug == 1) {
            return true;
        } else {
            return false;
        }
    }

    /**
     * hook、inject检测
     *
     * @return true hook、inject
     */
    public boolean injectCheck() {
        int debug = secureApi.injectCheck();
        if (debug == 0) {
            return false;
        } else {
            return true;
        }
    }

    /**
     * VirtualApp 检测
     *
     * @param cxt 上下文
     * @return ture 运行在VirtualApp
     */
    public boolean isRunInVa(Context cxt) {
        if (cxt == null) {
            throw new IllegalArgumentException("the context must be notnull");
        }
        int pid = Process.myPid();
        String process = getProcessName(cxt, pid);
        if (TextUtils.isEmpty(process)) {
            throw new RuntimeException("get process name failed");
        }
        String pkg = cxt.getPackageName();
        if (TextUtils.isEmpty(pkg)) {
            throw new RuntimeException("get package name failed");
        }
        return pkg.equals(process) && secureApi.isRunInVa() > 0;
    }

    /**
     * 多开环境检测测
     *
     * @param cxt 上下文
     * @return ture 运行在VirtualApp
     */
    public boolean isMultiOpen(Context cxt) {
        if (cxt == null) {
            throw new IllegalArgumentException("the context must be notnull");
        }
        int pid = Process.myPid();
        String process = getProcessName(cxt, pid);
        if (TextUtils.isEmpty(process)) {
            throw new RuntimeException("get process name failed");
        }
        String pkg = cxt.getPackageName();
        if (TextUtils.isEmpty(pkg)) {
            throw new RuntimeException("get package name failed");
        }
        return pkg.equals(process) && secureApi.isMultiOpen() > 0;
    }

    /**
     * 过滤当前非主进程的进程
     *
     * @param cxt 上下文
     * @param pid 进程id
     * @return
     */
    private static String getProcessName(Context cxt, int pid) {
        try {
            ActivityManager am = (ActivityManager) cxt.getSystemService(Context.ACTIVITY_SERVICE);
            List<ActivityManager.RunningAppProcessInfo> runningApps = am.getRunningAppProcesses();
            if (runningApps != null && !runningApps.isEmpty()) {
                for (ActivityManager.RunningAppProcessInfo procInfo : runningApps) {
                    if (procInfo.pid == pid) {
                        return procInfo.processName;
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }
}
