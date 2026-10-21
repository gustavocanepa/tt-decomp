#include "types.h"
struct Obj {
    char pad0[0x50];
    f32 f50;
    char pad1[0x68 - 0x54];
    s32 i60;
    f32 f64;
};
extern "C" void func_0013C948(Obj *o, s32 a) {
    if (a) {
        o->f50 = 1.0f;
        o->f64 = 0.0083333333f;
    } else {
        o->f50 = 0;
        o->f64 = -0.0083333333f;
    }
    o->i60 = 0;
}
