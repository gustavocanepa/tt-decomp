#include "types.h"

struct Func005F3B48Obj {
    f32 x0;
    f32 x1;
    f32 x2;
    f32 x3;
    f32 x4;
};

extern "C" void func_005511E0(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 fparg0) {
    struct Func005F3B48Obj *o = (struct Func005F3B48Obj *)(arg0 + 0xE390);

    o->x4 = fparg0;
    o->x0 = (f32) (arg1 - arg3 / 2);
    o->x1 = (f32) (arg2 - arg4 / 2);
    o->x2 = (f32) arg3;
    o->x3 = (f32) arg4;
}
