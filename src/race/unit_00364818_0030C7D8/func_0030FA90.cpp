#include "types.h"

union func_0030FA90_f {
    f32 f;
    s32 i;
};

struct func_0030FA90_dst {
    union func_0030FA90_f unk0;
    union func_0030FA90_f unk4;
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
    char pad30[0x68 - 0x30];
    u8 unk68;
    u8 unk69;
};

struct func_0030FA90_src {
    char pad0[0x2C];
    u8 n2C;
    u8 n2D;
    u8 n2E;
    u8 n2F;
    u8 n30;
    u8 n31;
    u8 n32;
    u8 n33;
    u8 n34;
};

struct func_0030FA90_glob {
    char pad0[0xBE];
    u8 unkBE;
    char padBF[3];
    u8 unkC2;
    u8 unkC3;
};

extern char D_00583868[];

extern "C" void func_0030FA90(struct func_0030FA90_dst *arg0, struct func_0030FA90_src *arg1) {
    struct func_0030FA90_glob *g;
    u8 c3;

    if (arg1->n2C != 0 &&
        (u32)arg1->n33 < (u32)arg1->n2C &&
        (u32)arg1->n34 < (u32)arg1->n2D &&
        (u32)arg1->n31 < (u32)arg1->n33 &&
        (u32)arg1->n32 < (u32)arg1->n34 &&
        (u32)arg1->n2E < (u32)arg1->n2D) {
        arg0->unk18 = (f32)arg1->n2C * 10000.0f;
        arg0->unk1C = (f32)arg1->n2D * 0x1.47ae14p-7f;
        arg0->unk20 = (f32)(100 - arg1->n2E) * 0x1.47ae14p-7f;
        if (arg0->unk69 != 0) {
            arg0->unk0.i = 0;
            arg0->unk4.i = 0;
        } else {
            arg0->unk0.f = -(f32)arg1->n2F * 10000.0f;
            arg0->unk4.f = (f32)arg1->n30 * 0x1.47ae14p-7f;
        }
        g = (struct func_0030FA90_glob *)D_00583868;
        arg0->unk8 = (f32)arg1->n31 * 10000.0f;
        arg0->unkC = (f32)arg1->n32 * 0x1.47ae14p-7f;
        arg0->unk10 = (f32)arg1->n33 * 10000.0f;
        arg0->unk14 = (f32)arg1->n34 * 0x1.47ae14p-7f;
        arg0->unk24 = (f32)g->unkBE / 100.0f;
        arg0->unk28 = (f32)g->unkC2 / 100.0f;
        c3 = g->unkC3;
        arg0->unk68 = 1;
        arg0->unk2C = -(f32)c3 / 100.0f;
    }
}
