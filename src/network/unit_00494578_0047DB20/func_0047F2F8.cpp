#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, void *);
};

struct Target {
    char pad[0xA4];
    char *vtbl;
};

extern "C" Target *func_0047F398(void *);

extern "C" s32 func_0047F2F8(void *self) {
    Target *t = func_0047F398(self);
    VEntry *e = (VEntry *)(t->vtbl + 0xB0);
    return e->fn((char *)t + e->delta, self);
}
