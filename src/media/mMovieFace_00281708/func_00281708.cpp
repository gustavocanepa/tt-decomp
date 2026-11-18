#include "types.h"

extern "C" void func_0029CF48(s32 *arg0, s32 arg1);
extern "C" s32 func_0029E9F0(s32 arg0);
extern "C" void func_00283058(s32 arg0, s32 arg1);
extern "C" void func_00281258(s32 *arg0, s32 arg1);

extern "C" void func_002812B0(s32 *arg0, s32 arg1);
extern "C" void func_0029CEF0(s32 *arg0, s32 arg1);

extern "C" void func_00281708(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 buf0[4];
    s32 buf1[4];

    if (arg2 > 0) {
        func_002812B0(buf0, arg1);
        s32 *p1 = buf1;
        func_0029CF48(p1, arg3);
        s32 base0 = buf0[0];
        s32 result = func_0029E9F0(p1[0]);
        func_00283058(base0, result);
        func_0029CEF0(p1, 2);
        func_00281258(buf0, 2);
    }
}
