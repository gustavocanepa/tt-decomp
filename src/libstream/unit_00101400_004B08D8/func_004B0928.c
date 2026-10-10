#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

u32 *func_00571EE8(s32, s32);                       /* extern */

struct func_004B0928_arg0 {
    u64 unk0;
    void *unk8;
    u32 *unkC;
    char pad10[0x10];
    s16 unk20;
};

void func_004B0928(struct func_004B0928_arg0 *arg0, s32 arg1, s32 arg2) {
    s16 temp_s0_2;
    s32 temp_s0;
    u32 *temp_v0;
    u32 temp_v1;
    void *temp_v0_2;

    temp_s0 = arg1 & 3;
    temp_s0_2 = temp_s0 * 8;
    temp_v0 = func_00571EE8(arg1, -temp_s0);
    temp_v1 = *temp_v0;
    temp_v0_2 = temp_v0 + 1;
    arg0->unk20 = (s16) -temp_s0_2;
    arg0->unk8 = temp_v0_2;
    arg0->unk0 = (u64) ((u64) ((s64) (temp_v1 >> temp_s0_2) << 0x20) >> 0x20);
    arg0->unkC = func_00571EE8(arg1, arg2);
}
