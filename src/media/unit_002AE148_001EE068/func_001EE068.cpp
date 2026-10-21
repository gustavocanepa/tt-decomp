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

extern "C" void func_001EDC38(s32 *buf);
extern "C" void func_001EEB30(s32 arg0, s32 arg1);
extern "C" void func_001EDBE0(void *buf, s32 arg1);

extern "C" void func_001EE068(s32 arg0, s32 arg1, s32 arg2, Arg3 *arg3) {
    if (arg2 > 0) {
        s32 buf[4];
        s32 s0;
        ObjA *obj;
        VEntry *entry;
        s32 result;

        func_001EDC38(buf);
        s0 = buf[0];
        obj = arg3->obj;
        entry = obj->vtbl + 12;
        result = entry->fn((char *)obj + entry->delta);
        func_001EEB30(s0, result);
        func_001EDBE0(buf, 2);
    }
}
