#include "types.h"

extern "C" void func_0041ECD0(s32 *arg0);
extern "C" void func_0041CF28(void *arg0, s32 arg1, s32 arg2);

struct VEntry_38 { s16 delta; s16 index; s32 (*fn)(void *); };

/* the object's table pointer sits at +8; the virtual entry is at +0x38 */
static inline s32 vcall_38(char *o) {
    VEntry_38 *e = (VEntry_38 *)(*(char **)(o + 8) + 0x40);
    return e->fn(o + e->delta);
}

extern "C" void func_00343F40(void *arg0, s32 *arg1) {
    char *self = (char *)arg0;
    s32 r;

    if (arg1 != 0) {
        func_0041ECD0(arg1);
    }
    r = vcall_38(self);
    func_0041CF28(self + 0x18, r, (s32)arg1);
    *(s32 *)(self + 0x354C) = 1;
}
