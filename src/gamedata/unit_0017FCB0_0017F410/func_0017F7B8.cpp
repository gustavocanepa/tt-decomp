#include "types.h"

extern "C" void func_0017C448(void *arg0, int arg1);
extern "C" void func_0017C4A0(void *arg0, void *arg1);
extern "C" void func_0017EC18(s32 arg0, s32 arg1);
extern "C" void func_001DF1F8(void *arg0, int arg1);
extern "C" void func_001DF250(void *arg0, void *arg1);

extern "C" void func_0017F7B8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 s0 = arg3;

    if (arg2 == 1) {
        s32 buf0[4];
        s32 buf1[4];

        func_0017C4A0(buf0, (void *)arg1);
        s32 *p1 = buf1;
        func_001DF250(p1, (void *)s0);
        func_0017EC18(buf0[0], p1[0]);
        func_001DF1F8(p1, 2);
        func_0017C448(buf0, 2);
    }
}
