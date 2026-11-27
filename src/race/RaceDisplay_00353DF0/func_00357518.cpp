#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32);
};

struct Self {
    char *vtbl;
    char pad0[0x20 - 4];
    s32 unk20;
    char pad1[0x64 - 0x24];
    s32 unk64;
};

extern "C" void func_00357518(Self *self) {
    Self *p = self;
    if ((unsigned int)(p->unk20 - 2) < 2u) {
        s32 v = p->unk64 + 1;
        p->unk64 = v;
        if (v >= 3) {
            p->unk64 = 0;
        }
        VEntry *e = (VEntry *)(p->vtbl + 0x1E8);
        e->fn((char *)p + e->delta, p->unk64);
    }
}
