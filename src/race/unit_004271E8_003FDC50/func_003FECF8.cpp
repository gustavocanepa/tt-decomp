#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *self, s32 a, s32 b);
};

struct Obj {
    s32 handle;
    s32 pad4[2];
    VEntry *vtbl;
};

extern "C" s32 func_003FEB98(s32 handle, s32 key);

extern "C" s32 func_003FECF8(Obj *self, s32 key, s32 value) {
    s32 r = func_003FEB98(self->handle, key);
    VEntry *e = &self->vtbl[6];
    return e->fn((char *)self + e->delta, r, value);
}
