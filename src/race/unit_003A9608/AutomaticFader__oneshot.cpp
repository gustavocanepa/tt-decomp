#include "types.h"

struct AutomaticFader__oneshot {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    s32 unk18;
};

extern f32 D_005F57DC;

extern "C" void AutomaticFader__oneshot(struct AutomaticFader__oneshot *self, f32 a0, f32 a1, f32 a2, f32 a3) {
    self->unk4 = a0;
    self->unk8 = a1;
    self->unk18 = 0;
    self->unk14 = a0;
    if (a0 <= 0.0f) {
        self->unk18 = 1;
        self->unk14 = a1;
        if (a1 == 0.0f && a2 <= 0.0f) {
            self->unk18 = 2;
            self->unk0 = 0x1.000000p+0f;
        }
    }
    if (a2 <= 0.0f)
        self->unkC = D_005F57DC;
    else
        self->unkC = 0x1.000000p+0f / a2;
    if (a3 <= 0.0f) {
        self->unk10 = D_005F57DC;
        return;
    }
    self->unk10 = 0x1.000000p+0f / a3;
}
