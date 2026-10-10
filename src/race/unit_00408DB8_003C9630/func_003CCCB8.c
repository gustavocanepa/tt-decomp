#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004172F0();                                /* extern */
s32 func_00418278(s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32); /* extern */
void *func_0041FFD8(s32, s32);                  /* extern */

struct func_003CCCB8_temp_s0 {
    char pad0[0x4];
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
    f32 unk40;
};

s32 func_003CCCB8(s32 arg0, s32 arg1, s32 arg2) {
    struct func_003CCCB8_temp_s0 *temp_s0;

    if (arg2 != 0) {
        temp_s0 = func_0041FFD8(arg2, 0x800000);
        if ((func_004172F0() != 0) && (temp_s0 != NULL)) {
            func_00418278(func_004172F0(), arg1, temp_s0->unk4, temp_s0->unk8, temp_s0->unkC, temp_s0->unk10, temp_s0->unk14, temp_s0->unk18, temp_s0->unk1C, temp_s0->unk20, temp_s0->unk24, temp_s0->unk28, temp_s0->unk2C, temp_s0->unk30, temp_s0->unk34, temp_s0->unk38, temp_s0->unk3C, temp_s0->unk40);
            return 1;
        }
    }
    return 0;
}
