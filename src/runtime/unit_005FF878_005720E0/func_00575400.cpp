#include "types.h"

extern "C" s32 func_004E3600(s32 arg0, s8 arg1);

extern "C" s32 func_00575400(s32 arg0, s32 arg1) {
    return func_004E3600(arg0, (s8)arg1);
}
