#include "types.h"

extern u8 D_00616779[];

extern "C" s32 func_005683A8(s8 arg0, s8 arg1) {
    s32 v = arg1;

    if (D_00616779[arg1] & 2) {
        v = arg1 - 0x20;
    }
    return arg0 < v;
}
