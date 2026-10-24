#include "types.h"

struct Obj {
    char pad[0x184];
    s32 unk180;
};

extern "C" void func_00324F10(struct Obj *arg0, s32 arg1);

extern "C" void func_00324EF0(struct Obj *arg0, s32 arg1) {
    arg0->unk180 = arg1;
    func_00324F10(arg0, 0);
}
