#include "types.h"

extern "C" s32 func_004B58C8(s32 arg0, s32 arg1, s32 arg2);

extern "C" s32 func_002D02A8(s32 arg0, s32 arg1) {
    return func_004B58C8(0, arg0, arg1);
}
