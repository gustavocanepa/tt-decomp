#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00435088(s32, s32, f32, s32, s32);
s32 func_00435280(void);
s32 func_004352A0(s32);
s32 func_00435330(s32 arg0, s32 arg1, f32 fparg0) {
    s32 temp_s1;
    temp_s1 = func_00435280();
    return func_00435088(arg0 + 0x8C, arg1, fparg0, temp_s1, func_004352A0(arg0));
}
