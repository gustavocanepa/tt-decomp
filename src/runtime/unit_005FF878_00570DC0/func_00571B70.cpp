#include "types.h"

extern "C" void func_004ACC20(s32 *arg0, s32 arg1, s32 arg2);

extern "C" void func_00571B70(s32 *arg0, s32 arg1) {
    func_004ACC20(arg0, *arg0, arg1);
}
