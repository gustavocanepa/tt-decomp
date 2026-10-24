#include "types.h"

extern "C" s32 func_004A4660(s32 arg0, s32 arg1);

extern "C" s32 func_004A47F8(s32 arg0, s32 arg1, s32 arg2) {
    return func_004A4660(arg1, arg2);
}
