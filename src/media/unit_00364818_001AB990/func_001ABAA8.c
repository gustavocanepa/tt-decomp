#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001AB9A0(f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32); /* extern */
f32 func_004A5DE0(f32);                             /* extern */

void func_001ABAA8(f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4, f32 fparg5, f32 fparg6, f32 fparg7, f32 arg_sp0, f32 arg_sp8, f32 arg_sp10) {
    f32 temp_f20;
    f32 temp_f21;

    temp_f20 = fparg2 * func_004A5DE0(fparg0 * 0x1.1df46a0000000p-6f * 0x1.0000000000000p-1f);
    temp_f21 = temp_f20 * fparg1;
    func_001AB9A0(-temp_f21, temp_f21, -temp_f20, temp_f20, fparg2, fparg3, fparg4, fparg5, fparg6, fparg7, arg_sp0, arg_sp8, arg_sp10);
}
