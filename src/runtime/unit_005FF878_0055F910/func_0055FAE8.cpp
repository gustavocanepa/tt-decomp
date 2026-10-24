#include "types.h"

struct Inner {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

struct Obj {
    char pad[0x10];
    Inner unk10;
    union { char *p; s32 i; } unk20;
    char pad24[0x1C];
    f32 unk40;
    f32 unk44;
};

extern "C" char D_005D71E8[];

extern "C" void func_0055FAE8(Obj *arg0) {
    f32 zero = 0.0f;
    f32 one = 1.0f;
    Inner *v0 = &arg0->unk10;
    v0->unk0 = zero;
    v0->unk4 = zero;
    v0->unk8 = zero;
    v0->unkC = one;
    arg0->unk40 = zero;
    arg0->unk44 = zero;
    arg0->unk20.p = D_005D71E8;
}
