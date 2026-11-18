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
    s32 unk0;
};

extern "C" void func_00139C38(s32 *buf, s32 arg);
extern "C" void func_0013C928(s32 arg0, f32 fparg0);
extern "C" void func_00139BE0(void *buf, s32 arg);

extern "C" void func_0013AF60(s32 arg0, s32 arg1, s32 arg2, Arg3 *arg3) {
    s32 buf[4];
    ObjA *obj = (ObjA *)arg3->unk0;
    VEntry *entry = obj->vtbl + 14;
    f32 f;
    f = entry->fn((char *)obj + entry->delta);
    func_00139C38(buf, arg1);
    func_0013C928(buf[0], f);
    func_00139BE0(buf, 2);
}
