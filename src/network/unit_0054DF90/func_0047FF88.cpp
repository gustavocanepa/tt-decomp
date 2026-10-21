#include "types.h"

struct Obj {
    char pad0[0x1A80];
    s32 f3290;
    char pad3294[4];
    s32 f3298;
    char pad329C[0x14];
    s32 f32B0;
};

extern "C" s32 func_0047F180(s32 a, void *b);
extern "C" void func_004AEAF8(void *arg0);
extern "C" void func_004AEB30(void *arg0);

extern "C" void func_0047FF88(void *arg0) {
    struct Obj *o = (struct Obj *)arg0;
    s32 t;

    while (func_004AEAF8((char *)o + 0x19C0), o->f3290 != 0) {
        t = func_0047F180(o->f3298, (char *)o + 0x1A8C);
        if (t < 0) {
            o->f32B0 = t;
        }
        func_004AEB30((char *)o + 0x19F0);
    }
}
