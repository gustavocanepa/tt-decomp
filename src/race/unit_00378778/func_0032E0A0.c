#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_005357F8(s32);                             /* extern */

struct func_0032E0A0_arg0 {
    f32 unk0;
    f32 unk4;
    s32 unk8;
    s32 unkC;
};

void func_0032E0A0(struct func_0032E0A0_arg0 *arg0, s32 arg1) {
    f32 temp_f0;
    f32 temp_f0_2;

    temp_f0 = func_005357F8(arg1);
    temp_f0_2 = temp_f0 * 0x1.0000000000000p+8f;
    arg0->unkC = 0;
    arg0->unk8 = 0;
    arg0->unk0 = temp_f0_2;
    arg0->unk4 = temp_f0_2;
}
