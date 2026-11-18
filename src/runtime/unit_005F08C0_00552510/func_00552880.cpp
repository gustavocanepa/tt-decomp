#include "types.h"

extern "C" s32 func_002F04D8(s32 arg0, s32 arg1);

extern "C" s32 func_00552880(s32 arg0, s32 arg1) {
    return func_002F04D8(arg0, arg1) + 0x104;
}
