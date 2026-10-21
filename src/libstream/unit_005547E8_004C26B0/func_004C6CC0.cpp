#include "types.h"

struct Obj {
    char pad[0x10];
    s32 unk10;
};

extern "C" void func_004C5740(s32 arg0, struct Obj *arg1);

extern "C" void func_004C6CC0(struct Obj *arg0) {
    func_004C5740(arg0->unk10, arg0);
}
