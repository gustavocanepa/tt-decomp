#include "types.h"
extern "C" s32 func_004A8368(const char *s);
extern "C" void func_004F7A30(char *dst, const char *src);
extern "C" int func_004A8E90(char *buf, s32 arg1, s32 arg2);

extern "C" void func_004A8F88(const char *arg0, const char *arg1, const char *arg2, s32 arg3, s32 arg4) {
    u32 n = func_004A8368(arg1) + 1;
    if (arg0 != 0) {
        n += func_004A8368(arg0);
    }
    if (arg2 != 0) {
        n += func_004A8368(arg2);
    }
    char *buf = (char *)__builtin_alloca(n);
    buf[0] = 0;
    if (arg0 != 0) {
        func_004F7A30(buf, arg0);
    }
    func_004F7A30(buf, arg1);
    if (arg2 != 0) {
        func_004F7A30(buf, arg2);
    }
    func_004A8E90(buf, arg3, arg4);
}
