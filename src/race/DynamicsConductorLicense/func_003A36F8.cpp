#include "types.h"

struct Obj_3F6140 {
    char pad0[0x241CC];
    char *vtbl;
};

struct VEntry_3F6140 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, void *, s32);
};

extern "C" s16 func_002E4CB0(void *);
extern "C" s32 DynamicsConductor__getNumberOfLoggerSections(void *);
extern "C" s32 func_002FD9C0(void *, void *, s32);

extern "C" s32 func_003A36F8(char *arg0, char *arg1, s32 arg2) {
    Obj_3F6140 *o = (Obj_3F6140 *)arg0;
    VEntry_3F6140 *e = (VEntry_3F6140 *)(o->vtbl + 0x40);
    if (e->fn((char *)o + e->delta, arg1, arg2) == 0) {
        return func_002FD9C0(arg0, arg1, arg2);
    } else {
        s32 s0 = func_002E4CB0(arg1);
        s32 n = DynamicsConductor__getNumberOfLoggerSections(arg0);
        s32 temp = (s0 - 1) * n + *(u8 *)(arg1 + 0x5D8);
        s32 r = temp - 1;
        if (arg2 == 0) {
            r = temp;
        }
        return r;
    }
}
