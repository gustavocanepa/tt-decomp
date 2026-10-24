#include "types.h"

extern "C" void func_002063E0(s32 arg0, s32 arg1, void *arg2, s32 arg3, s32 arg4);

extern "C" f32 func_00206330(s32 arg0) {
    f32 sp[4];
    func_002063E0(arg0, 0, sp, 0, 0);
    return sp[0];
}
