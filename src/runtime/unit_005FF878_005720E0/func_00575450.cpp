#include "types.h"

extern "C" s32 func_004E3A58(s32 arg0, s16 arg1);

extern "C" s32 func_00575450(s32 arg0, s32 arg1) {
    return func_004E3A58(arg0, (s16)arg1);
}
