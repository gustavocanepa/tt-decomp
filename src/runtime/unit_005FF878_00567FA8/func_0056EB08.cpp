#include "types.h"

struct P8 {
    s32 a;
    s32 b;
};

struct Obj0060B1E8 {
    char pad0[0x18];
    P8 m18;
};

extern "C" void func_0056EB08(struct Obj0060B1E8 *arg0, s32 arg1, s32 arg2) {
    P8 t;
    t.a = arg1;
    t.b = arg2;
    arg0->m18 = t;
}
