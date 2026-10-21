#include "types.h"

extern "C" void func_0027BEF0(s32 *arg0);
extern "C" void func_0029B4E0(s32 *arg0, s32 arg1);
extern "C" void func_0027F070(s32 arg0, s32 *arg1);
extern "C" void func_0029B488(s32 *arg0, s32 arg1);
extern "C" void func_0027BE98(s32 *arg0, s32 arg1);

extern "C" void func_0027C9F8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg2 > 0) {
        s32 buf0[4];
        s32 buf1[4];

        func_0027BEF0(buf0);
        func_0029B4E0(buf1, arg3);
        func_0027F070(buf0[0], buf1);
        func_0029B488(buf1, 2);
        func_0027BE98(buf0, 2);
    }
}
