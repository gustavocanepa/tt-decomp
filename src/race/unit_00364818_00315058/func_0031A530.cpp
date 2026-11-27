#include "types.h"

struct VEntryD8 {
    s16 delta;
    s16 index;
    void *(*fn)(void *, s32);
};

struct VEntry110 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

extern "C" f32 func_0031A530(char *arg0) {
    f32 temp_f20 = 8.0f;
    void *obj;
    VEntryD8 *e;

    e = (VEntryD8 *)(*(char **)arg0 + 0xE0);
    obj = e->fn(arg0 + e->delta, *(s32 *)(arg0 + 0xA4C));
    if (obj != 0) {
        VEntry110 *g = (VEntry110 *)(*(char **)obj + 0x120);
        s32 v = g->fn((char *)obj + g->delta);
        temp_f20 = (f32)v / 100.0f;
    }
    return temp_f20;
}
