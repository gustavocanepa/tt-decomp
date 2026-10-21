#include "types.h"

struct VEntry { short delta; short index; void (*fn)(void *); };
struct Obj { char pad[0x84]; s32 f84; char pad88[0x20]; VEntry *vtbl; };
extern "C" void func_0047C9F8(Obj *);

static inline void vcall(Obj *o, int slot) {
    VEntry *e = o->vtbl + slot;
    e->fn((char *)o + e->delta);
}

extern "C" void func_0047C9A8(Obj *o) {
    if (o->f84)
        func_0047C9F8(o);
    vcall(o, 8);
}
