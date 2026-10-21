#include "types.h"

struct VEntry { s16 delta; s16 index; void (*fn)(void *); };
struct VObj { s32 m0; VEntry *vtbl; };
struct Guard { VObj *p; s32 pad[3]; };
extern "C" void func_00201CF0(Guard *);
extern "C" void func_00201C98(Guard *, s32);

extern "C" void func_00201EA8(void) {
    Guard g;
    func_00201CF0(&g);
    {
        VObj *o = g.p;
        VEntry *e = &o->vtbl[54];
        e->fn((char *)o + e->delta);
    }
    func_00201C98(&g, 2);
}
