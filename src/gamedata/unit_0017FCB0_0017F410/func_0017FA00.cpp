#include "types.h"

struct VEntry {
    s16 delta;
    s16 pad;
    f32 (*fn)(void *);
};

struct ObjA {
    char pad0[4];
    VEntry *vtbl;
};

struct Arg3 {
    ObjA *obj;
};

extern "C" void func_0017C4A0(s32 *buf);
extern "C" void func_0017DB10(s32 arg0, f32 arg1);
extern "C" void func_0017C448(s32 *buf, s32 arg1);

extern "C" void func_0017FA00(s32 arg0, s32 arg1, s32 arg2, Arg3 *arg3) {
    s32 buf[4];
    s32 s0;
    ObjA *obj;
    VEntry *entry;
    f32 result;

    if (arg2 == 1) {
        func_0017C4A0(buf);
        s0 = buf[0];
        obj = arg3->obj;
        entry = obj->vtbl + 14;
        result = entry->fn((char *)obj + entry->delta);
        func_0017DB10(s0, result);
        func_0017C448(buf, 2);
    }
}
