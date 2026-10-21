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

extern "C" void func_00128418(void *arg0, int arg1);
extern "C" void func_00128470(void *arg0);
extern "C" s32 func_001324D8(s32 arg0);
extern "C" void func_0029CEF0(void *arg0, int arg1);
extern "C" void func_0029EA18(void *arg0, s32 arg1);
extern "C" void func_002C0FE8(s32 arg0);
extern "C" void func_002C1050(s32 arg0);
extern "C" s32 func_00406888(s32 arg0);
extern "C" s32 func_004068B0(s32 arg0);

extern "C" void func_001377C8(s32 *arg0, s32 arg1, s32 n, Obj **args) {
    s32 buf[4];
    s32 h;
    s32 r;
    s32 v;
    s32 newVal;
    s32 oldVal;
    func_00128470(buf);
    h = func_001324D8(buf[0]);
    func_00128418(buf, 2);
    {
        Obj *o = *args;
        VEntry *e = (VEntry *)(o->vtbl + 0x68);
        r = e->fn((char *)o + e->delta);
    }
    switch (r) {
    case 0:
        v = func_00406888(h);
        break;
    case 1:
        v = func_004068B0(h);
        break;
    default:
        v = -1;
        break;
    }
    func_0029EA18(buf, v);
    if (arg0 != buf) {
        newVal = buf[0];
        if (newVal != 0) {
            func_002C0FE8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_002C1050(oldVal);
        }
        *arg0 = newVal;
    }
    func_0029CEF0(buf, 2);
}
