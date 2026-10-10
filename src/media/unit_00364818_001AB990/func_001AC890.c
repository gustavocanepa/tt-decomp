#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001AC890_arg2 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};
struct func_001AC890_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};
struct func_001AC890_arg0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    f32 unk3C;
};

void func_001AC890(struct func_001AC890_arg0 *arg0, struct func_001AC890_arg1 *arg1, struct func_001AC890_arg2 *arg2) {
    f32 temp_f4;
    f32 temp_f5;

    temp_f4 = arg2->unk0 * arg1->unk0;
    temp_f5 = temp_f4 + (arg2->unk4 * arg1->unk4) + (arg2->unk8 * arg1->unk8) + (arg2->unkC * arg1->unkC);
    arg0->unk0 = (f32) (temp_f5 - temp_f4);
    arg0->unk10 = (f32) (-arg1->unk0 * arg2->unk4);
    arg0->unk20 = (f32) (-arg1->unk0 * arg2->unk8);
    arg0->unk30 = (f32) (-arg1->unk0 * arg2->unkC);
    arg0->unk4 = (f32) (-arg1->unk4 * arg2->unk0);
    arg0->unk14 = (f32) (temp_f5 - (arg1->unk4 * arg2->unk4));
    arg0->unk24 = (f32) (-arg1->unk4 * arg2->unk8);
    arg0->unk34 = (f32) (-arg1->unk4 * arg2->unkC);
    arg0->unk8 = (f32) (-arg1->unk8 * arg2->unk0);
    arg0->unk18 = (f32) (-arg1->unk8 * arg2->unk4);
    arg0->unk28 = (f32) (temp_f5 - (arg1->unk8 * arg2->unk8));
    arg0->unk38 = (f32) (-arg1->unk8 * arg2->unkC);
    arg0->unkC = (f32) (-arg1->unkC * arg2->unk0);
    arg0->unk1C = (f32) (-arg1->unkC * arg2->unk4);
    arg0->unk2C = (f32) (-arg1->unkC * arg2->unk8);
    arg0->unk3C = (f32) (temp_f5 - (arg1->unkC * arg2->unkC));
}
