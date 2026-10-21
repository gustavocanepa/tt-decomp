#include "types.h"

struct VEntry {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, s32);
};

struct Obj {
    char pad0[0x64];
    VEntry *vtbl;
    s32 unk68;
    s32 unk6C;
    s32 unk70;
};

extern "C" u32 func_00535818(s32 arg0);
extern "C" void func_00396308(void *arg0, s32 arg1);
extern "C" void func_0039A130(void *arg0, s32 arg1, f32 arg2);

extern "C" void func_002CF420(Obj *self, f32 t) {
    char *s1 = (char *)self + 0x36C0;
    VEntry *e = &self->vtbl[26];
    s32 v = e->fn((char *)self + e->delta, 0);
    func_00396308(s1, func_00535818(v + 4));
    func_0039A130(s1, self->unk70, t);
}
