#include "types.h"

extern "C" s32 func_004E6338(s32 arg0, s8 arg1);

extern "C" s32 func_004E5458(s32 arg0, s32 arg1) {
    return func_004E6338(arg0, (s8)arg1);
}
