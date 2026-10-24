#include "types.h"

extern "C" s32 func_004694D0(f32 arg0, f32 arg1, f32 arg2, f32 arg3);

extern "C" s32 func_004694B0(f32 arg0, f32 arg1, f32 arg2) {
    return func_004694D0(arg0, arg1, arg2, 1.0f);
}
