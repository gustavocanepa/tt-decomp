#include "types.h"

extern "C" s32 func_0040BDF8(s32 arg0, s32 arg1);
extern "C" void func_0040BCE8(s32 arg0, s32 arg1);

extern "C" s32 func_0040BCB0(s32 arg0, s32 arg1) {
    func_0040BCE8(arg0, arg1);
    return func_0040BDF8(arg0, arg1);
}
