#include "types.h"

struct Pair {
    s32 a;
    s32 b;
};

struct State {
    Pair p0;
    Pair p8;
    Pair p10;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
};

extern Pair D_005981D8;
extern Pair D_005981E0;

extern "C" void func_004A8C08(State *s, const Pair *p) {
    s->p0 = D_005981D8;
    s->p8 = *p;
    s->p10 = D_005981E0;
    s->unk18 = 0;
    s->unk1C = 0;
    s->unk20 = 0;
    s->unk24 = 0;
}
