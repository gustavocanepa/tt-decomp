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

extern "C" void func_001DF250(void *, void *);
extern "C" void func_001DF1F8(void *, s32);
extern "C" void func_0029CF48(void *, void *);
extern "C" void func_00269F40(void *, void *);
extern "C" s32 func_0029E9F0(s32);
extern "C" void func_0026C250(s32, s32, s32);
extern "C" void func_00269EE8(void *, s32);
extern "C" void func_0029CEF0(void *, s32);

extern "C" void MOptionMenu__setIndex(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 v_s2;
    s32 *p_s0;
    s32 v_s1;
    if (arg2 >= 0x2) {
        v_s2 = 0;
        if (*(s32 *)(char *)arg3 != 0) {
            func_001DF250(buf0, arg3);
            v_s2 = buf0[0];
            func_001DF1F8(buf0, 0x2);
        }
        func_0029CF48(buf0, (char *)arg3 + 0x4);
        p_s0 = buf1;
        func_00269F40(p_s0, arg1);
        v_s1 = *p_s0;
        func_0026C250(v_s1, v_s2, func_0029E9F0(buf0[0]));
        func_00269EE8(p_s0, 0x2);
        func_0029CEF0(buf0, 0x2);
    }
}
