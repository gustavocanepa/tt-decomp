#include "types.h"

struct VEntryF_002331C0 {
    s16 delta;
    s16 index;
    f32 (*fn)(void *);
};

struct VObj_002331C0 {
    char pad0[4];
    char *vtbl;
};

extern "C" void func_001E6428(void *arg0, int arg1);
extern "C" void func_001E6480(void *arg0, void *arg1);
extern "C" void func_00206008(void *c, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);

extern "C" void func_001E6A30(s32 *arg0, void *arg1, s32 arg2, VObj_002331C0 **arg3) {
    void *buf0[4];
    if (arg2 >= 2) {
        func_001E6480(buf0, arg1);
        {
            void *hv = buf0[0];
            VObj_002331C0 *o = arg3[0];
            VEntryF_002331C0 *e = (VEntryF_002331C0 *)(o->vtbl + 0x70);
            f32 a = e->fn((char *)o + e->delta);
            VObj_002331C0 *o2 = arg3[1];
            VEntryF_002331C0 *e2 = (VEntryF_002331C0 *)(o2->vtbl + 0x70);
            func_00206008(hv, 0.0f, 0.0f, a, e2->fn((char *)o2 + e2->delta));
        }
        func_001E6428(buf0, 2);
    }
}
