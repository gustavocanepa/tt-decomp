#include "types.h"

extern "C" s32 func_004E48B0(s32 arg0, s32 arg1, s32 arg2, s8 arg3);

extern "C" s32 func_00575778(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return func_004E48B0(arg0, arg1, arg2, (s8)arg3);
}
