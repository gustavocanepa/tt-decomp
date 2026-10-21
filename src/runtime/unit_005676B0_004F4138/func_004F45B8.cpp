#include "types.h"

extern "C" void func_004F4438(s32 arg0, s32 arg1, s32 arg2);

extern "C" void func_004F45B8(s32 arg0, s32 arg1) {
    func_004F4438(arg0 + 4, arg1, 0);
}
