#include "types.h"

struct VEntry {
    s16 delta;
    s16 pad;
    s32 (*fn)(void *);
};

struct ObjA {
    char pad0[4];
    VEntry *vtbl;
};

extern "C" void func_001DD608(void *buf);
extern "C" void func_001DE3C8(s32 arg0, s32 arg1);
extern "C" void func_001DD5B0(void *buf, s32 arg1);

extern "C" void func_001DDA90(s32 arg0, s32 arg1, s32 arg2, ObjA **arg3) {
    if (arg2 > 0) {
        s32 buf[4];
        s32 s0;
        ObjA *o;
        VEntry *e;

        func_001DD608(buf);
        s0 = buf[0];
        o = *arg3;
        e = o->vtbl + 13;
        func_001DE3C8(s0, e->fn((char *)o + e->delta) != 0);
        func_001DD5B0(buf, 2);
    }
}
