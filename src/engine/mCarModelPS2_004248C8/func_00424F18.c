#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_0030C5D8(s32, s32, f32, f32);              /* extern */
f32 func_0030C610(s32, s32, f32, f32);              /* extern */

struct func_00424F18_temp_s0_2 {
    char pad0[0x4];
    f32 unk4;
    char pad8[0x4];
    f32 unkC;
    s32 unk10;
};
struct func_00424F18_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

struct func_00424F18_temp_s0 {
    char pad0[0x20];
    f32 unk20;
};
struct func_00424F18_arg1 {
    char pad0[0x4];
    s32 unk4;
};

void *func_00424F18(struct func_00424F18_arg0 *arg0, void *arg1, s32 arg2) {
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f22;
    s32 temp_s3;
    void *temp_s0;
    struct func_00424F18_temp_s0_2 *temp_s0_2;

    temp_s0 = arg1 + (arg2 * 0x14);
    temp_s0_2 = temp_s0 + 0x20;
    temp_s3 = temp_s0_2->unk10;
    temp_f20 = ((struct func_00424F18_temp_s0 *)temp_s0)->unk20 * 0x1.1df46a0000000p-6f;
    temp_f22 = temp_s0_2->unk4;
    temp_f21 = func_0030C5D8(((struct func_00424F18_arg1 *)arg1)->unk4, temp_s3, temp_f20, temp_s0_2->unkC) * 0x1.ca5dc00000000p+5f;
    temp_f0 = func_0030C610(((struct func_00424F18_arg1 *)arg1)->unk4, temp_s3, temp_f20, temp_s0_2->unkC);
    arg0->unk0 = temp_f22;
    arg0->unk4 = temp_f21;
    arg0->unk8 = (f32) (temp_f0 * 0x1.ca5dc00000000p+5f);
    return arg0;
}
