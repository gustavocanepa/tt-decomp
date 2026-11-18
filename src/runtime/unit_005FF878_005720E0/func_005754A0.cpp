#include "types.h"

extern "C" s32 func_004B4C18(s32 arg0);
extern "C" s32 func_004E3D60(s32 arg0, s32 arg1);

extern "C" s32 func_005754A0(s32 arg0)
{
    s32 s0 = arg0;
    s32 v0 = func_004B4C18(arg0);
    return func_004E3D60(s0, v0);
}
