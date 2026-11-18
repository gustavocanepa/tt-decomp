#include "types.h"

struct Pair {
    u16 normal;
    u16 alt;
};

struct Obj {
    s32 unk0;
    s32 flags;
    char pad8[8];
    s32 ids[16];
    s32 altIds[16];
};

extern Pair D_007A5F60[];

extern "C" u16 func_004C09F0(Obj *o, s32 i, s32 useAlt) {
    Pair *p;
    if (useAlt == 0)
        p = &D_007A5F60[o->ids[i]];
    else
        p = &D_007A5F60[o->altIds[i]];
    if (o->flags & 0x22)
        return p->alt;
    return p->normal;
}
