#include "types.h"

struct Obj {
    char pad[4];
    s32 unk4;
};

extern "C" void func_00249650(s32 arg0, s32 arg1, struct Obj *arg2);

extern "C" void func_0053E288(struct Obj *arg0, s32 arg1) {
    func_00249650(arg0->unk4, arg1, arg0);
}
