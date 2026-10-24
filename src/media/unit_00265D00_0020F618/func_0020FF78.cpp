#include "types.h"

extern "C" void func_001C2E70(s32 *arg0);
extern "C" void func_001C2A20(s32 *arg0, s32 arg1);

extern "C" s32 func_0020FF78(void) {
    s32 local;
    s32 s0;

    func_001C2E70(&local);
    s0 = local;
    func_001C2A20(&local, 2);
    return s0;
}
