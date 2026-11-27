#include "types.h"

extern "C" s32 func_0047DB20(s32 arg0, s32 arg1, s32 arg2);

extern "C" s32 func_00460840(s32 arg0) {
    s32 buf[8];
    func_0047DB20((s32)buf, arg0, 1);
    return buf[4];
}
