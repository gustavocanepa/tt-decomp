#include "types.h"

extern "C" s32 func_0040BCF0(s32 arg0);
extern "C" void func_0040BCE8(s32 arg0);

extern "C" s32 func_0040BBD0(s32 arg0)
{
    s32 s0 = arg0;
    func_0040BCE8(s0);
    return func_0040BCF0(s0);
}
