#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Obj {
    char pad[0x4C];
    char *vtbl;
};

extern "C" const char D_005E6C98[];
extern "C" const char D_005E6CD8[];

extern "C" const char *func_001A0DD0(Obj *self) {
    VEntry *e = (VEntry *)(self->vtbl + 0x130);
    if (e->fn((char *)self + e->delta))
        return D_005E6C98;
    return D_005E6CD8;
}
