#include "types.h"

struct func_001BED60_arg0 {
    char pad0[0x50];
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    char pad24[0x8];
    f32 unk2C;
    f32 unk30;
    s32 unk34;
};

void func_001BED60(struct func_001BED60_arg0 *arg0) {
    f32 r;

    if (arg0->unk34 != 0) {
        if (arg0->unk1C < arg0->unk20) {
            if (0.0f <= arg0->unk2C) {
                r = arg0->unk20 + arg0->unk2C;
            } else {
                r = arg0->unk20 - arg0->unk2C;
            }
        } else {
            if (0.0f <= arg0->unk2C) {
                r = arg0->unk20 - arg0->unk2C;
            } else {
                r = arg0->unk20 + arg0->unk2C;
            }
        }
    } else {
        f32 a = arg0->unk1C;
        f32 b = arg0->unk20;
        if (a < b) {
            if (0.0f <= arg0->unk30) {
                r = a - arg0->unk30;
            } else {
                r = a + arg0->unk30;
            }
        } else {
            if (0.0f <= arg0->unk30) {
                r = a + arg0->unk30;
            } else {
                r = a - arg0->unk30;
            }
        }
    }
    arg0->unk18 = r;
}
