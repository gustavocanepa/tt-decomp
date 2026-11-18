#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, s32);
};

struct Obj {
    char pad0[0x64];
    VEntry *vtbl;
};

extern "C" Obj *func_002C6290(void);

extern "C" s32 func_002C6298(void) {
    Obj *o = func_002C6290();
    VEntry *e = o->vtbl + 26;
    return e->fn((char *)o + e->delta, 0);
}
