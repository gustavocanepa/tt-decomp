#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *self, s32 a, s32 b);
};

struct Manager {
    char pad0[0xA4];
    VEntry *vtbl;
};

extern "C" Manager *func_0047F398(void);

extern "C" s32 func_0047F340(s32 a, s32 b) {
    Manager *m = func_0047F398();
    VEntry *e = &m->vtbl[24];
    return e->fn((char *)m + e->delta, a, b);
}
