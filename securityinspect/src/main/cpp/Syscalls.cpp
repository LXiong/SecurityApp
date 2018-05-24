//
// Created by qtfreet00 on 2018/1/22.
//

#include "Syscalls.h"
#include <asm/unistd.h>
#include "fcntl.h"


int _gettimeofday(struct timeval *tv, struct timezone *tz) {
    int ret = (int) syscall(__NR_gettimeofday, tv, tz);
    return ret;
}

int _kill(pid_t pid, int signal) {
    int ret = (int) syscall(__NR_kill, pid, signal);
    return ret;
}

pid_t _getpid(void) {
    pid_t pid = (pid_t) syscall(__NR_getpid);
    return pid;
}

uid_t _getuid(void) {
    uid_t uid = (uid_t) syscall(__NR_getuid);
    return uid;
}

__noreturn void _exit(int i) {
    syscall(__NR_exit, i);
}

int _faccessat(int dirfd, const char *pathname, int mode, int flags) {
    int ret = (int) syscall(__NR_faccessat, dirfd, pathname, mode, flags);
    return ret;
}

int _open(const char *__path, int __flags) {
    int ret;
#if defined(__aarch64__)
    ret = open(__path, __flags);
#else
    ret = syscall(__NR_open, __path, __flags);
#endif
    return ret;
}

ssize_t _read(int __fd, void *__buf, size_t __count) {
    ssize_t ret = syscall(__NR_read, __fd, __buf, __count);
    return ret;
}

int _access(const char *file, int mode) {
    int ret;
#if defined(__aarch64__)
    ret = access(file, mode);
#else
    ret = syscall(__NR_access, file, mode);
#endif
    return ret;
}

int _close(int fd) {
    return (int) syscall(__NR_close, fd);
}

int _openat(int __dir_fd, const char *__path, int __flags) {
    int ret = (int) syscall(__NR_openat, __dir_fd, __path, __flags);
    return ret;
}
