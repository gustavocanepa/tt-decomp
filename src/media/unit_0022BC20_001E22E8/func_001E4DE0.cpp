#include "types.h"

struct VEntry { s16 delta; s16 index; void (*fn)(void *, void *, s32); };
struct VObj { VEntry *vtbl; };
struct Self { char pad[0x6D4]; VObj *m6D4; };

extern "C" void func_001E4DE0(Self *self, s32 a) {
    VObj *o = self->m6D4;
    if (o != 0) {
        VEntry *e = &o->vtbl[3];
        e->fn((char *)o + e->delta, self, a);
    }
}
