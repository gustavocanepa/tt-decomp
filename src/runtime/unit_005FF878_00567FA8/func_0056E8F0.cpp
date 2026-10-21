#include "types.h"

struct Obj {
    char pad[0x38];
    s32 unk38;
};

extern "C" void func_0047CBF8(s32 arg0, struct Obj *arg1);

extern "C" void func_0056E8F0(struct Obj *arg0) {
    func_0047CBF8(arg0->unk38, arg0);
}
