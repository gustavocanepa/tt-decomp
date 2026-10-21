#include "types.h"

extern "C" s32 func_004694D0(f32 arg0, f32 arg1, f32 arg2, f32 arg3);

extern "C" s32 func_00469488(f32 fparg0) {
    return func_004694D0(fparg0, fparg0, fparg0, 1.0f);
}
