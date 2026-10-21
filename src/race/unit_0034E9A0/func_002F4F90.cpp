#include "types.h"

struct Obj {
    char pad0[0xC];
    f32 unkC;
};

extern "C" void func_002F4E60(Obj *arg0);

extern "C" f32 func_002F4F90(Obj *arg0) {
    func_002F4E60(arg0);
    return arg0->unkC;
}
