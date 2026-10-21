#include "types.h"

extern "C" void func_001C7410(s32 v);

struct VEntry_0024F748 {
    s16 delta;
    s16 index;
    f32 (*fn)(void *);
};

struct Obj_0024F748 {
    void *f0;
    char *vtbl;
};

extern "C" void func_001FE380(s32 v, s32 n, Obj_0024F748 **arg2) {
    v = 1;
    if (n > 0) {
        Obj_0024F748 *o = *arg2;
        VEntry_0024F748 *e = (VEntry_0024F748 *)(o->vtbl + 0x70);
        f32 f = e->fn((char *)o + e->delta);
        v = (s32)(f * 0x1.Ep5f);
    }
    func_001C7410(v);
}
