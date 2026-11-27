#include "types.h"

struct VEntry {
    short delta;
    short index;
    s32 (*fn)(void *);
};

struct VObj {
    char pad0[4];
    char *vtbl;
};

struct Obj {
    char pad0[4];
};

extern "C" void func_002931C8(void *arg0, int arg1);
extern "C" void func_00293220(void *arg0, void *arg1);
extern "C" s32 func_00294F40(Obj *arg0);
extern "C" void func_00294F58(Obj *arg0, s32 v);
extern "C" void func_0029CEF0(void *arg0, int arg1);
extern "C" void func_0029EA18(void *arg0, s32 fparg0);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);

extern "C" void func_00293B90(s32 *arg0, void *arg1, s32 arg2, VObj **arg3) {
    Obj *h[4];
    if (arg2 == 0) {
        s32 buf[4];
        s32 *buf0;
        s32 newVal;
        s32 oldVal;
        s32 f;
        func_00293220(h, arg1);
        f = func_00294F40(h[0]);
        buf0 = buf;
        func_0029EA18(buf0, f);
        if (arg0 != buf0) {
            newVal = buf0[0];
            if (newVal != 0) {
                func_002C0FE8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_002C1050(oldVal);
            }
            *arg0 = newVal;
        }
        func_0029CEF0(buf0, 2);
        func_002931C8(h, 2);
    } else if (arg2 == 1) {
        func_00293220(h, arg1);
        {
            Obj *hv = h[0];
            VObj *o = *arg3;
            VEntry *e = (VEntry *)(o->vtbl + 0x68);
            func_00294F58(hv, e->fn((char *)o + e->delta));
        }
        func_002931C8(h, 2);
    }
}
