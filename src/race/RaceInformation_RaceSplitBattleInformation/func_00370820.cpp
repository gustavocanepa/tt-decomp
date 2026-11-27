#include "types.h"

extern "C" s32 D_00584580;

extern "C" void func_00370820(s32 arg0, s32 arg1) {
    if (arg1 == 0xFFFF && arg0 == 1) {
        D_00584580 = 0x12345678;
    }
}
