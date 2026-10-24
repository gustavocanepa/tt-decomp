#include "types.h"

struct VEntryD8 {
    s16 delta;
    s16 index;
    void *(*fn)(void *, s32);
};

struct VEntry108 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

extern "C" f32 func_004170D8(char *self);

extern "C" f32 func_0031A738(char *arg0) {
    f32 temp_f20;
    VEntryD8 *e;
    char *r;

    temp_f20 = func_004170D8(arg0);
    e = (VEntryD8 *)(*(char **)arg0 + 0xE0);
    r = (char *)e->fn(arg0 + e->delta, *(s32 *)(arg0 + 0xA4C));
    if (r != 0) {
        VEntry108 *g = (VEntry108 *)(*(char **)r + 0x118);
        s32 v = g->fn(r + g->delta);
        temp_f20 = (f32)v / 10.0f;
    }
    return temp_f20 / 1000.0f;
}
