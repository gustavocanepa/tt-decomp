#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00306FB0_temp_a0 {
    char pad0[0x89];
    u8 unk89;
    char pad8A[0x2A];
    f32 unkB4;
    f32 unkB8;
};

void func_00306FB0(s32 arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 fparg0, f32 fparg1) {
    u8 temp_a1;
    struct func_00306FB0_temp_a0 *temp_a0;

    temp_a0 = arg0 + (arg1 * 0xF4) + 0x164;
    temp_a1 = temp_a0->unk89;
    if ((temp_a1 == 1) || (temp_a1 == 0x15)) {
        *arg2 = fparg0 * temp_a0->unkB4;
        *arg3 = fparg1 * temp_a0->unkB8;
    }
}
