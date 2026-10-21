#include "types.h"

struct Obj {
    char pad0[0x70];
    s32 unk70;
};

extern "C" void func_00375840(Obj *arg0);

extern "C" void func_00375888(Obj *arg0, s32 arg1) {
    func_00375840(arg0);
    arg0->unk70 = arg1;
}
