/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 Oscillator__setCount(void *, s32, s32);        /* extern */
s32 AutomaticFader__oneshot(s32, f32, f32, f32, f32);     /* extern */

struct func_0035BA00_temp_a0 {
    char pad0[0x4];
    s32 unk4;
};

struct func_0035BA00_arg0 {
    char pad0[0x20];
    f32 unk20;
    f32 unk24;
    s32 unk28;
};

void func_0035BA00(void *arg0, f32 fparg0, f32 fparg1) {
    struct func_0035BA00_temp_a0 *temp_a0;

    AutomaticFader__oneshot(arg0 + 0x2C, fparg1, fparg0, ((struct func_0035BA00_arg0 *)arg0)->unk20, ((struct func_0035BA00_arg0 *)arg0)->unk24);
    temp_a0 = arg0 + 0x48;
    temp_a0->unk4 = 0;
    Oscillator__setCount(temp_a0, ((struct func_0035BA00_arg0 *)arg0)->unk28, 1);
}
