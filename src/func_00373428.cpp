/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0

extern "C" {
void Oscillator__setCycle(void *, f32, f32);
void func_0035E878(void *, f32, f32);
void Oscillator__setCount(void *, s32, u8);
}

extern "C" void func_00373428(char *arg0, char *arg1) {
    char *self;
    char *temp_a1;
    char *temp_a3;
    unsigned long v1;
    unsigned long v2;

    self = arg0;
    char *osc=self+0x48;
    *(f32 *)(self + 0x34) = 1.0f;
    *(f32 *)(self + 0x38) = 1.0f;
    temp_a1 = *(char **)(*(char **)(*(char **)(arg1 + 0x80) + 4) + 0x84);
    *(char **)(self + 0x18) = temp_a1;
    temp_a3 = *(char **)(temp_a1 + 0x28);
    v1 = *(unsigned long *)(*(char **)(temp_a3 + 0x18) + 0x20);
    *(s16 *)(self + 0x3C) = (s16)((((v1 >> 14) & 0x3FF) + 1) & 0xFFFF);
    v2 = *(unsigned long *)(*(char **)(temp_a3 + 0x18) + 0x20);
    *(s16 *)(self + 0x3E) = (s16)((((v2 >> 34) & 0x3FF) + 1) & 0xFFFF);
    *(s32 *)(self + 0x44) = 0;
    *(s32 *)(self + 0x40) = 0;
    Oscillator__setCycle(osc, 0.5f, 0.5f);
    func_0035E878(osc, 0x1.999998p-4f, 0x1.333332p-2f);
    Oscillator__setCount(osc, -1, 0);
}
