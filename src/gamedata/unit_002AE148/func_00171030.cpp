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

extern "C" void func_0016E838(s32 *buf);
extern "C" void func_0016E7E0(s32 *buf, s32 arg);
extern "C" void func_00382150(void *p, s32 v);

extern "C" void func_00171030(s32 arg0, s32 arg1, s32 n, Arg3 *arg3) {
    if (n > 0) {
        s32 buf[4];
        s32 off;
        ObjA *obj;
        VEntry *entry;
        s32 result;

        func_0016E838(buf);
        obj = arg3->obj;
        entry = obj->vtbl + 13;
        off = buf[0] + 0x10;
        result = entry->fn((char *)obj + entry->delta);
        func_00382150((void *)off, result);
        func_0016E7E0(buf, 2);
    }
}
