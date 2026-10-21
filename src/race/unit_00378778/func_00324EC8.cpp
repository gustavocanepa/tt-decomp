#include "types.h"

struct Obj {
    char pad0[0x184];
    s32 unk180;
};

extern "C" void func_00324F10(Obj *arg0, s32 arg1, s32 arg2);

extern "C" void func_00324EC8(Obj *arg0, s32 arg1) {
    arg0->unk180 = arg1;
    func_00324F10(arg0, 0, 0);
}
