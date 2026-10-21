#include "types.h"

struct Obj {
    char pad[0x18];
    f32 unk18;
};

extern "C" void func_00106C20(Obj *arg0);

extern "C" void func_00106BE0(Obj *arg0, f32 arg1) {
    arg0->unk18 = arg1;
    func_00106C20(arg0);
}
