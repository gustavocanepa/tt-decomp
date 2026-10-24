#include "types.h"

struct VEntry { s16 delta; s16 index; s32 (*fn)(void *); };
struct VObj { char pad[0x64]; VEntry *vtbl; };
struct Self { char pad[0x84]; VObj *m84; };

static inline s32 vcall(VObj *o) {
    VEntry *e = &o->vtbl[83];
    return e->fn((char *)o + e->delta);
}

extern "C" s32 func_00376B50(Self *self) {
    VObj *o = self->m84;
    if (o != 0) return vcall(o);
    return 0;
}
