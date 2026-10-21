#include "types.h"

struct Obj {
    char pad[0x6E0];
    s32 unk6E0;
};

extern "C" void func_00198980(Obj *arg0);
extern "C" void func_00198940(Obj *arg0, s32 arg1);

extern "C" void func_00198A90(Obj *arg0) {
    if (arg0->unk6E0 == 0) {
        return func_00198980(arg0);
    }
    func_00198940(arg0, 0);
}
