#include "types.h"

struct VEntry { s16 delta; s16 index; void (*fn)(void *); };
struct VObj { s32 m0; VEntry *vtbl; };
struct Guard { VObj *p; s32 pad[3]; };
extern "C" void func_001B3470(Guard *);
extern "C" void func_001B3418(Guard *, s32);

extern "C" void func_001B3718(void) {
    Guard g;
    func_001B3470(&g);
    {
        VObj *o = g.p;
        VEntry *e = &o->vtbl[78];
        e->fn((char *)o + e->delta);
    }
    func_001B3418(&g, 2);
}
