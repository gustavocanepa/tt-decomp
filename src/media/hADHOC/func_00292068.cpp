#include "types.h"

extern "C" void func_002A2758(s32 arg0, s32 arg1);

extern "C" s32 func_00292068(s32 arg0, s32 arg1) {
    s32 s0 = arg0;
    func_002A2758(s0, arg1 + 0x38);
    return s0;
}
