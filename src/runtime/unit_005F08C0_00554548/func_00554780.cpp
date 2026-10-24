#include "types.h"

struct Obj {
    char pad[0xE4D0];
    s32 unkE408;
};

extern "C" void func_0033E230(struct Obj *arg0, s32 arg1);

extern "C" void func_00554780(struct Obj *arg0) {
    func_0033E230(arg0, arg0->unkE408);
}
