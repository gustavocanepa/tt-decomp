#include "types.h"

struct VEntry_00436E18 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, s32);
};

struct Obj_00436E18 {
    char pad0[0x48];
    VEntry_00436E18 e;
};

extern "C" s32 func_00403568(void *arg0);
extern "C" void **func_00403590(void *arg0, s32 arg1);

extern "C" s32 func_003FD640(void *arg0, s32 arg1, s32 arg2) {
    void *s1 = (char *)arg0 + 0x1238;
    if (arg1 < func_00403568(s1)) {
        void **p = func_00403590(s1, arg1);
        Obj_00436E18 *o = (Obj_00436E18 *)(*(s32 *)p);
        VEntry_00436E18 *e = &o->e;
        return e->fn((char *)p + e->delta, arg2);
    }
    return 0;
}
