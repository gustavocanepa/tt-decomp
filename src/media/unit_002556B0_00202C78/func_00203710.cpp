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

extern "C" void func_002027E0(void *buf, s32 arg);
extern "C" void func_00202788(void *buf, s32 arg);
extern "C" void func_0020D6C8(s32 obj, s32 flag);

extern "C" void func_00203710(s32 unused, s32 arg1, s32 arg2, Arg3 *arg3) {
    s32 buf[4];
    s32 flag = 1;
    if (arg2 != 0) {
        ObjA *obj = arg3->obj;
        VEntry *entry = obj->vtbl + 13;
        s32 result = entry->fn((char *)obj + entry->delta);
        flag = result != 0;
    }
    func_002027E0(buf, arg1);
    func_0020D6C8(buf[0], flag);
    func_00202788(buf, 2);
}
