#include "types.h"

struct Obj {
    char pad[0xC];
    f32 unkC;
};

extern "C" void func_00475730(f32 arg0);

extern "C" void func_0041D9A0(struct Obj *arg0) {
    func_00475730(arg0->unkC);
}
