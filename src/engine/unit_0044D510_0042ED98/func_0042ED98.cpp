#include "types.h"

extern char D_0042EDC8[];

struct P8 {
    s32 a;
    s32 b;
};

struct Obj0044D510 {
    char pad0[0x18];
    P8 m18;
};

extern "C" void func_0042ED98(struct Obj0044D510 *arg0, s32 arg1) {
    P8 t;
    t.a = (s32)D_0042EDC8;
    t.b = arg1;
    arg0->m18 = t;
}
