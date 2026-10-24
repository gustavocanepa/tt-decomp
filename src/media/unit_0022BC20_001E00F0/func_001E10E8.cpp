#include "types.h"

struct VEntry { s16 delta; s16 index; void (*fn)(void *); };
struct VObj { s32 m0; VEntry *vtbl; };
struct Guard { VObj *p; s32 pad[3]; };
extern "C" void func_001DF250(Guard *);
extern "C" void func_001DF1F8(Guard *, s32);

extern "C" void func_001E10E8(void) {
    Guard g;
    func_001DF250(&g);
    {
        VObj *o = g.p;
        VEntry *e = &o->vtbl[76];
        e->fn((char *)o + e->delta);
    }
    func_001DF1F8(&g, 2);
}
