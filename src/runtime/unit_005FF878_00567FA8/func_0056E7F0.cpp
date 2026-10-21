#include "types.h"

struct VEntry { s16 delta; s16 index; s32 (*fn)(void *, void *, s32, s32); };
struct VObj { char pad[0xA4]; VEntry *vtbl; };
struct Arg { s32 a, b; };
struct Self { char pad[0x38]; VObj *m38; };

extern "C" void func_0056E7F0(Self *self, Arg *arg) {
    VObj *o = self->m38;
    VEntry *e = &o->vtbl[16];
    e->fn((char *)o + e->delta, self, arg->a, arg->b);
}
