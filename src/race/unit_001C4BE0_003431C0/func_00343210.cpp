#include "types.h"

struct S0038F8A0 {
    char pad0[0x94];
    s32 unk94;
};

extern "C" void func_00344148(void *arg0, s32 arg1);

extern "C" void func_00343210(void *arg0, S0038F8A0 *arg1) {
    func_00344148(arg0, arg1->unk94);
}
