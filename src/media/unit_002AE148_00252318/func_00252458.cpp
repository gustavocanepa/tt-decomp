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

struct Arg3 {
    ObjA *obj;
};

extern "C" void func_00251678(s32 *buf);
extern "C" void func_00257200(s32 arg0, s32 arg1);
extern "C" void func_00251620(s32 *buf, s32 arg1);

extern "C" void func_00252458(s32 arg0, s32 arg1, s32 arg2, Arg3 *arg3) {
    s32 buf[4];
    s32 s0;
    ObjA *obj;
    VEntry *entry;
    s32 result;

    if (arg2 == 1) {
        func_00251678(buf);
        s0 = buf[0];
        obj = arg3->obj;
        entry = obj->vtbl + 13;
        result = entry->fn((char *)obj + entry->delta);
        func_00257200(s0, result);
        func_00251620(buf, 2);
    }
}
