#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_002E1DC8_arg0 {
    char pad0[0x24];
    void *unk24;
};
struct func_002E1DC8_arg2 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};
struct func_002E1DC8_temp_v0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};
struct func_002E1DC8_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

void func_002E1DC8(struct func_002E1DC8_arg0 *arg0, struct func_002E1DC8_arg1 *arg1, struct func_002E1DC8_arg2 *arg2) {
    f32 temp_f1;
    f32 temp_f4;
    struct func_002E1DC8_temp_v0 *temp_v0;

    temp_v0 = arg0->unk24;
    temp_f4 = arg2->unk0;
    temp_f1 = -temp_v0->unkC / ((temp_f4 * temp_v0->unk0) + (arg2->unk4 * temp_v0->unk4) + (arg2->unk8 * temp_v0->unk8));
    arg1->unk0 = (f32) (temp_f1 * temp_f4);
    arg1->unk4 = (f32) (temp_f1 * arg2->unk4);
    arg1->unk8 = (f32) (temp_f1 * arg2->unk8);
}
