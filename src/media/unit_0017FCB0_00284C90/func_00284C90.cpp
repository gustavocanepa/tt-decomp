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

extern "C" void func_00284978(s32 *buf);
extern "C" void func_00284F90(s32 arg0, f32 arg1);
extern "C" void func_00284920(s32 *buf, s32 arg1);

extern "C" void func_00284C90(s32 arg0, s32 arg1, s32 n, Arg3 *arg3) {
    if (n > 0) {
        s32 buf[4];
        s32 s0;
        ObjA *obj;
        VEntry *entry;
        f32 result;

        func_00284978(buf);
        s0 = buf[0];
        obj = arg3->obj;
        entry = obj->vtbl + 14;
        result = entry->fn((char *)obj + entry->delta);
        func_00284F90(s0, result);
        func_00284920(buf, 2);
    }
}
