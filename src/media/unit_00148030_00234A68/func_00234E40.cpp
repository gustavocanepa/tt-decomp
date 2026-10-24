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

extern "C" void func_00234728(s32 *buf, s32 arg);
extern "C" void func_002346D0(s32 *buf, s32 arg);
extern "C" void func_00236568(s32 obj, s32 flag);

extern "C" void func_00234E40(s32 unused, s32 arg1, s32 count, Arg3 *arg3) {
    if (count > 0) {
        ObjA *obj = arg3->obj;
        VEntry *entry = obj->vtbl + 13;
        s32 result = entry->fn((char *)obj + entry->delta);
        s32 buf[4];
        s32 flag = result != 0;
        func_00234728(buf, arg1);
        func_00236568(buf[0], flag);
        func_002346D0(buf, 2);
    }
}
