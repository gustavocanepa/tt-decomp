/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003D0C48(s32, s32, s32, s32, s32, s32, f32, f32, f32, f32); /* extern */
s32 func_003D1158();                                /* extern */

struct func_003D11C0_arg0 {
    char pad0[0x12C8];
    s32 unk12C8;
    s32 unk12CC;
};

void func_003D11C0(void *arg0, s32 arg1, s32 arg2, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3) {
    if (func_003D1158() != 0) {
        func_003D0C48(arg0 + (arg1 * 0x320), arg1, ((struct func_003D11C0_arg0 *)arg0)->unk12C8, ((struct func_003D11C0_arg0 *)arg0)->unk12CC, arg2, arg0 + 0x12C0, fparg0, fparg1, fparg2, fparg3);
    }
}
