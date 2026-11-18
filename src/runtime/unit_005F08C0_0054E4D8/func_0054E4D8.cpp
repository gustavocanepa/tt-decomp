#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *);
};

struct Holder {
    char pad[8];
    void **top;
};

struct Self {
    char pad[0x10];
    Holder h;
};

extern "C" s32 func_0054E4D8(Self *self) {
    void *obj = self->h.top[-1];
    VEntry *e = (VEntry *)((char *)*(void **)obj + 0x10);
    return ((s32 (*)(void *))e->fn)((char *)obj + e->delta);
}
