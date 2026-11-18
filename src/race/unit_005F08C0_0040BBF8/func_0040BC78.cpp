#include "types.h"

extern "C" s32 func_0040BE90(s32 arg0, s32 arg1);
extern "C" void func_0040BCE8(s32 arg0, s32 arg1);

extern "C" s32 func_0040BC78(s32 arg0, s32 arg1) {
    func_0040BCE8(arg0, arg1);
    return func_0040BE90(arg0, arg1);
}
