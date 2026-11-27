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

extern "C" void func_0021EF48(void *);
extern "C" void func_001DF250(void *, void *);
extern "C" void func_002027E0(void *, void *);
extern "C" void func_0022F7C0(s32, s32);
extern "C" void func_0022F820(s32, s32);
extern "C" void func_00202788(void *, s32);
extern "C" void func_001DF1F8(void *, s32);
extern "C" void func_0021EEF0(void *, s32);

extern "C" void func_0021F098(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 *p_s1;
    s32 *p_s0;
    if (arg2 == 0x2) {
        func_0021EF48(buf0);
        p_s1 = buf1;
        func_001DF250(p_s1, arg3);
        p_s0 = buf2;
        func_002027E0(p_s0, (char *)arg3 + 0x4);
        func_0022F7C0(buf0[0], *p_s1);
        func_0022F820(buf0[0], *p_s0);
        func_00202788(p_s0, 0x2);
        func_001DF1F8(p_s1, 0x2);
        func_0021EEF0(buf0, 0x2);
    }
}
