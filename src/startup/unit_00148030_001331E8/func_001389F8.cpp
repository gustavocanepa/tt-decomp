#include "types.h"

struct RefCounter;

struct Setting {
    char pad0[8];
    f32 f8;
};

struct Obj {
    char pad0[4];
    char *vtbl;
};

struct VEntry {
    short delta;
    short index;
    f32 (*fn)(void *);
};

extern "C" void func_00128418(void *arg0, int arg1);
extern "C" void func_00128470(void *arg0, void *arg1);
extern "C" s32 func_001324D8(s32 arg0);
extern "C" void func_00299AB0(void *arg0, int arg1);
extern "C" void func_0029B380(void *arg0, f32 fparg0);
extern "C" void func_002C0FE8(RefCounter *p);
extern "C" void func_002C1050(RefCounter *p);
extern "C" void func_002E4800(Obj *o, f32 v);

extern "C" void func_001389F8(s32 *arg0, void *arg1, s32 n, Obj **args) {
    s32 buf[4];
    s32 newVal;
    s32 oldVal;
    Setting *s2;

    func_00128470(buf, arg1);
    s2 = (Setting *)(func_001324D8(buf[0]) + 0x4E8);
    func_00128418(buf, 2);
    if (n > 0) {
        Obj *o = args[0];
        VEntry *e = (VEntry *)(o->vtbl + 0x70);
        f32 v = e->fn((char *)o + e->delta);
        func_002E4800((Obj *)s2, v);
        return;
    }
    func_0029B380(buf, s2->f8);
    if (arg0 != buf) {
        newVal = buf[0];
        if (newVal != 0) {
            func_002C0FE8((RefCounter *)newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_002C1050((RefCounter *)oldVal);
        }
        *arg0 = newVal;
    }
    func_00299AB0(buf, 2);
}
