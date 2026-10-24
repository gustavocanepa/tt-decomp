#include "types.h"

extern "C" void func_00382A88(s32 arg0, s32 arg1);

extern "C" s32 func_00559B28(s32 arg0, s32 arg1) {
    s32 s0 = arg0;
    func_00382A88(s0, arg1 + 0x11D0);
    return s0;
}
