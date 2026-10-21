#include "types.h"

extern "C" s32 func_00403DF0(s32 arg0);
extern "C" s32 func_00404180(s32 arg0, s32 arg1);
extern "C" s32 func_00404570(s32 arg0, s32 arg1);
extern "C" s32 func_004049D8(s32 arg0, s32 arg1);

extern "C" s32 func_004033D8(s32 arg0) {
    s32 s0 = arg0;
    s32 v0;

    v0 = func_00403DF0(s0 + 0x18);
    v0 = func_00404180(s0 + 0x48, v0);
    v0 = func_00404570(s0 + 0x64, v0);
    return func_004049D8(s0 + 0x8C, v0);
}
