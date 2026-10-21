#include "types.h"

extern "C" void func_00205E78(s32 arg0, f32 *arg1, s32 arg2, s32 arg3, s32 arg4);

extern "C" f32 func_00205C50(s32 arg0) {
    f32 sp[4];
    func_00205E78(arg0, sp, 0, 0, 0);
    return sp[0];
}
