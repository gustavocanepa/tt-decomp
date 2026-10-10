#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00382A88();                            /* extern */

struct func_00382BF0_arg1 {
    char pad0[0x30];
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
    f32 unk40;
    f32 unk44;
    f32 unk48;
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 unk58;
    f32 unk5C;
};
struct func_00382BF0_temp_v1 {
    char pad0[0x4];
    f32 unk4;
    f32 unk8;
};
struct func_00382BF0_temp_a0 {
    char pad0[0x4];
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

struct func_00382BF0_arg0 {
    char pad0[0x30];
    f32 unk30;
    char pad34[0x8];
    f32 unk3C;
    char pad40[0xC];
    f32 unk4C;
    f32 unk50;
    f32 unk54;
    f32 unk58;
    f32 unk5C;
};

void *func_00382BF0(void *arg0, struct func_00382BF0_arg1 *arg1) {
    struct func_00382BF0_temp_a0 *temp_a0;
    struct func_00382BF0_temp_v1 *temp_v1;

    func_00382A88();
    temp_v1 = arg0 + 0x30;
    temp_a0 = arg0 + 0x3C;
    ((struct func_00382BF0_arg0 *)arg0)->unk30 = (f32) arg1->unk30;
    temp_v1->unk4 = (f32) arg1->unk34;
    temp_v1->unk8 = (f32) arg1->unk38;
    ((struct func_00382BF0_arg0 *)arg0)->unk3C = (f32) arg1->unk3C;
    temp_a0->unk4 = (f32) arg1->unk40;
    temp_a0->unk8 = (f32) arg1->unk44;
    temp_a0->unkC = (f32) arg1->unk48;
    ((struct func_00382BF0_arg0 *)arg0)->unk4C = (f32) arg1->unk4C;
    ((struct func_00382BF0_arg0 *)arg0)->unk50 = (f32) arg1->unk50;
    ((struct func_00382BF0_arg0 *)arg0)->unk54 = (f32) arg1->unk54;
    ((struct func_00382BF0_arg0 *)arg0)->unk58 = (f32) arg1->unk58;
    ((struct func_00382BF0_arg0 *)arg0)->unk5C = (f32) arg1->unk5C;
    return arg0;
}
