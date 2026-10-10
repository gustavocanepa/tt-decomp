#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004737C8(f32, f32, f32, f32, f32, f32, f32); /* extern */
f32 func_004A5DE0(f32);                             /* extern */

void func_00468C10(f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    f32 temp_f14;
    f32 temp_f20;

    temp_f20 = fparg2 * func_004A5DE0(fparg0 * 0x1.1df46a0000000p-7f);
    temp_f14 = -temp_f20;
    func_004737C8(temp_f14 * fparg1, temp_f20 * fparg1, temp_f14, temp_f20, fparg2, fparg3, fparg2);
}
