#include "types.h"

struct VEntry {
    short delta;
    short index;
    s32 (*fn)(void *);
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

extern s32 D_0057B1A4;

extern "C" void func_0029EA18(void *dst, s32 src);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);
extern "C" void func_0029CEF0(void *arg0, int arg1);

extern "C" void func_00212B40(s32 *arg0, s32 arg1, Obj **arg2) {
    s32 buf[4];

    if (arg1 == 0) {
        func_0029EA18(buf, D_0057B1A4);
        if (arg0 != buf) {
            s32 newVal = buf[0];
            if (newVal != 0) {
                func_002C0FE8(newVal);
            }
            s32 oldVal = *arg0;
            if (oldVal != 0) {
                func_002C1050(oldVal);
            }
            *arg0 = newVal;
        }
        func_0029CEF0(buf, 2);
    } else if (arg1 == 1) {
        Obj *o = *arg2;
        VEntry *e = (VEntry *)(o->vtbl + 0x68);
        D_0057B1A4 = e->fn((char *)o + e->delta);
    }
}
