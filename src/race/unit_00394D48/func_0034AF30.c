#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void *func_0034C5E8(s32);                           /* extern */

struct func_0034AF30_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0xB0];
    s32 unkB8;
};
struct func_0034AF30_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};
struct func_0034AF30_temp_v0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

void func_0034AF30(struct func_0034AF30_arg0 *arg0, struct func_0034AF30_arg1 *arg1, s32 arg2) {
    struct func_0034AF30_temp_v0 *temp_v0;

    temp_v0 = M2C_FIELD((M2C_FIELD(func_0034C5E8(arg0->unk4), s32 *, 0x9C) + (arg0->unkB8 << 5)), s32 *, 0x10) + (arg2 * 0x10);
    arg1->unk0 = (f32) temp_v0->unk0;
    arg1->unk4 = (f32) temp_v0->unk4;
    arg1->unk8 = (f32) temp_v0->unk8;
    arg1->unkC = (f32) temp_v0->unkC;
}
