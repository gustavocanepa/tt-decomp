#include "types.h"

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

extern "C" void func_00141000(void *);
extern "C" void func_0029CF48(void *, void *);
extern "C" s32 func_0029E9F0(s32);
extern "C" void func_0029CEF0(void *, s32);
extern "C" void func_003FAB10(s32, s32, s32, s32);
extern "C" void func_00140FA8(void *, s32);

extern "C" void MDemonstration__initialize(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 buf3[4];
    s32 v_s4;
    s32 *p_s3;
    s32 *p_s2;
    s32 *p_s0;
    s32 v_s1;
    s32 v_s0;
    if (!((arg2 < 0x2))) {
        v_s4 = 0x4;
        func_00141000(buf0);
        p_s3 = buf1;
        func_0029CF48(p_s3, arg3);
        p_s2 = buf2;
        func_0029CF48(p_s2, (char *)arg3 + 0x4);
        p_s0 = buf3;
        if (!((arg2 < 0x3))) {
            func_0029CF48(p_s0, (char *)arg3 + 0x8);
            v_s4 = func_0029E9F0(*p_s0);
            func_0029CEF0(p_s0, 0x2);
        }
        v_s1 = *(s32 *)((char *)buf0[0] + 0x10);
        v_s0 = func_0029E9F0(*p_s3);
        func_003FAB10(v_s1, v_s0, func_0029E9F0(*p_s2), v_s4);
        func_0029CEF0(p_s2, 0x2);
        func_0029CEF0(p_s3, 0x2);
        func_00140FA8(buf0, 0x2);
    }
}
