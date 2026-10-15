#include "types.h"

struct func_004552C8_arg0 {
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
struct func_004552C8_arg1 {
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

s32 func_004552C8(struct func_004552C8_arg0 *arg0, struct func_004552C8_arg1 *arg1) {
    s32 var_v0;
    f32 b;

    var_v0 = 0;
    b = arg1->unk0;
    if (arg0->unk0 == b) {
        b = arg1->unk4;
        if (arg0->unk4 == b) {
            b = arg1->unk8;
            if (arg0->unk8 == b) {
                b = arg1->unkC;
                if (arg0->unkC == b) {
                    b = arg1->unk10;
                    if (arg0->unk10 == b) {
                        b = arg1->unk14;
                        if (arg0->unk14 == b) {
                            b = arg1->unk18;
                            if (arg0->unk18 == b) {
                                b = arg1->unk1C;
                                if (arg0->unk1C == b) {
                                    b = arg1->unk20;
                                    if (arg0->unk20 == b) {
                                        b = arg1->unk24;
                                        if (arg0->unk24 == b) {
                                            b = arg1->unk28;
                                            if (arg0->unk28 == b) {
                                                b = arg1->unk2C;
                                                if (arg0->unk2C == b) {
                                                    b = arg1->unk30;
                                                    if (arg0->unk30 == b) {
                                                        b = arg1->unk34;
                                                        if (arg0->unk34 == b) {
                                                            b = arg1->unk38;
                                                            if (arg0->unk38 == b) {
                                                                var_v0 = 1;
                                                                b = arg1->unk3C;
                                                                if (arg0->unk3C != b) {
                                                                    var_v0 = 0;
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return var_v0;
}
