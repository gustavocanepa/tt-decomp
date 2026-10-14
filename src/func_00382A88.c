#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00382A80(s8 *, u8);                      /* extern */

struct func_00382A88_arg1 {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
    u16 unk6;
    u16 unk8;
    u16 unkA;
    u16 unkC;
    u16 unkE;
    u16 unk10;
    u16 unk12;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C;
    u8 unk1D;
    u8 unk1E;
    u8 unk1F;
    u8 unk20;
};

s8 *func_00382A88(s8 *arg0, struct func_00382A88_arg1 *arg1) {
    s8 *var_s0;

    var_s0 = arg0;
    *var_s0 = (s8) arg1->unk0;
    *(s8 *)(var_s0 + 1) = (s8) arg1->unk1;
    *(s8 *)(var_s0 + 2) = (s8) arg1->unk2;
    *(s8 *)(var_s0 + 3) = (s8) arg1->unk3;
    *(s8 *)(var_s0 + 4) = (s8) arg1->unk4;
    *(s8 *)(var_s0 + 5) = (s8) arg1->unk5;
    *(u16 *)(var_s0 + 6) = arg1->unk6;
    *(u16 *)(var_s0 + 8) = arg1->unk8;
    *(u16 *)(var_s0 + 0xA) = arg1->unkA;
    *(u16 *)(var_s0 + 0xC) = arg1->unkC;
    *(u16 *)(var_s0 + 0xE) = arg1->unkE;
    *(u16 *)(var_s0 + 0x10) = arg1->unk10;
    *(u16 *)(var_s0 + 0x12) = arg1->unk12;
    *(s8 *)(var_s0 + 0x14) = (s8) arg1->unk14;
    *(s8 *)(var_s0 + 0x15) = (s8) arg1->unk15;
    *(s8 *)(var_s0 + 0x16) = (s8) arg1->unk16;
    *(s8 *)(var_s0 + 0x17) = (s8) arg1->unk17;
    *(s8 *)(var_s0 + 0x18) = (s8) arg1->unk18;
    *(s8 *)(var_s0 + 0x19) = (s8) arg1->unk19;
    *(s8 *)(var_s0 + 0x1A) = (s8) arg1->unk1A;
    *(s8 *)(var_s0 + 0x1B) = (s8) arg1->unk1B;
    *(s8 *)(var_s0 + 0x1C) = (s8) arg1->unk1C;
    *(s8 *)(var_s0 + 0x1D) = (s8) arg1->unk1D;
    *(s8 *)(var_s0 + 0x1E) = (s8) arg1->unk1E;
    *(s8 *)(var_s0 + 0x1F) = (s8) arg1->unk1F;
    func_00382A80(var_s0, arg1->unk20);
    return var_s0;
}
