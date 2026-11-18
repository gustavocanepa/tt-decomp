#include "types.h"

extern "C" s32 func_004C9418(s32 arg0, s32 arg1);

extern "C" s32 func_004C9448(s32 arg0)
{
    s32 cond = arg0 >= 0x18;
    return func_004C9418(cond, cond ? arg0 - 0x18 : arg0);
}
