#include "types.h"

extern "C" s32 HIO__read32();

extern "C" s32 func_0029F850(s32 arg0, s32 *arg1) {
    s32 *s0 = arg1;
    s32 s1 = arg0;
    *s0 = HIO__read32();
    return s1;
}
