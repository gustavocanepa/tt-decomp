#include "types.h"

extern "C" void func_002AB418(s32 arg0, s32 arg1);

extern "C" s32 func_001DE5F8(s32 arg0, s32 arg1) {
    s32 s0 = arg0;
    func_002AB418(s0, arg1 + 0xD4);
    return s0;
}
