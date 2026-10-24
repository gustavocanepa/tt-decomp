#include "types.h"

struct Arg1 {
    char pad0[8];
    s32 unk8;
};

extern "C" f32 func_0043E0B0(s32 arg0);
extern "C" void func_00447D00(Arg1 *arg0, s32 arg1);
extern "C" void func_004EE530(f32 arg0);

extern "C" void func_00442AA8(s32 arg0, Arg1 *arg1) {
    f32 var20;

    if (arg0 != 0) {
        var20 = func_0043E0B0(arg1->unk8 - 8);
    } else {
        var20 = 0.0f;
    }
    func_00447D00(arg1, arg0);
    func_004EE530(var20);
}
