#include "types.h"

extern "C" void func_00573FC0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern "C" void func_004C6C08(s32 arg0, s32 arg1, s32 arg2)
{
    func_00573FC0(arg0, arg0 + 0x540, 2, arg1, arg2);
}
