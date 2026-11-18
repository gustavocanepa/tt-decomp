#include "types.h"

struct Obj {
    char pad[8];
    float unk8;
    float rate;
    char pad10[8];
    s32 unk18;
};

extern float D_005F57D4;

extern "C" void AutomaticFader__fadein(Obj *o, float t) {
    if (t <= 0.0f)
        o->rate = D_005F57D4;
    else
        o->rate = 1.0f / t;
    o->unk18 = 1;
    o->unk8 = -1.0f;
}
