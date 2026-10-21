#include "types.h"

extern "C" void func_004AC3E0(s32 arg0, s32 arg1, s32 *arg2);

extern "C" s32 func_004AC3B8(s32 arg0, s32 arg1, s32 arg2) {
    s32 local = arg2;
    func_004AC3E0(arg0, arg1, &local);
    return local;
}
