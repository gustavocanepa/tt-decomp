#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, void *, s32, s32);
};

struct Obj {
    char pad[0x4C];
    char *vt;
};

extern "C" s32 func_0019C448(void *arg0, void **arg1, s32 arg2, s32 arg3)
{
    s8 buf[0x50];
    struct Obj *self = (struct Obj *)arg0;
    struct VEntry *e = (struct VEntry *)(self->vt + 0x78);
    e->fn((char *)self + e->delta, buf, arg2, arg3);
    struct VEntry *f = (struct VEntry *)((char *)*arg1 + 0x80);
    return f->fn((char *)arg1 + f->delta, buf, arg2, arg3) == 0;
}
