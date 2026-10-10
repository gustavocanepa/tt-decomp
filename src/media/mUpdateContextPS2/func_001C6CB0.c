#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00211EB8(s32);
s32 func_004C99C0(s32, s32);
f32 func_001C6CB0(s32 arg0, s32 arg1, s32 arg2) {
    return (s16)func_004C99C0(func_00211EB8((arg1 * 0xD4) + arg0 + 0x1D8), arg2) * 0.0078125f;
}
