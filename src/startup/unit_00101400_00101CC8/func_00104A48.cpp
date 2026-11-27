#include "types.h"

extern "C" void func_00104A28(s32 arg0);
extern "C" void func_00104A38(s32 arg0, s32 arg2);

extern "C" void func_00104A48(s32 arg0, s32 arg1, s32 arg2) {
    func_00104A28(arg0);
    func_00104A38(arg0, arg2);
}
