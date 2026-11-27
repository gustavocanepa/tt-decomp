#include "types.h"

extern "C" void func_002A7590(s32 arg0, s32 arg1);

extern "C" s32 func_00256FE0(s32 arg0, s32 arg1) {
    s32 s0 = arg0;
    func_002A7590(s0, arg1 + 0x13C);
    return s0;
}
