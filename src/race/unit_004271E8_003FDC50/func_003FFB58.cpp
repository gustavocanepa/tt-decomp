#include "types.h"

extern "C" s32 func_004A81B8(s32 arg0, s32 arg1, s32 arg2);

extern "C" s32 func_003FFB58(s32 arg0, s32 arg1) {
    return (u32)func_004A81B8(arg0, arg1, 0x2C) < 1;
}
