#include "types.h"

extern "C" s32 func_004B65E8(void);
extern "C" s64 D_00598810;

extern "C" s64 func_004B6658(void) {
    return func_004B65E8() + D_00598810;
}
