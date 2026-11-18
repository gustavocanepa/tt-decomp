#include "types.h"

struct VEntry { s16 delta; s16 index; void (*fn)(void *); };
struct VObj { s32 m0; VEntry *vtbl; };
struct Guard { VObj *p; s32 pad[3]; };
extern "C" void func_001D35A0(Guard *);
extern "C" void func_001D3548(Guard *, s32);

extern "C" void func_001D5478(void) {
    Guard g;
    func_001D35A0(&g);
    {
        VObj *o = g.p;
        VEntry *e = &o->vtbl[86];
        e->fn((char *)o + e->delta);
    }
    func_001D3548(&g, 2);
}
