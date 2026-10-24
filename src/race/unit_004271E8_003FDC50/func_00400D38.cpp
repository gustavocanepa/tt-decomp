#include "types.h"

extern "C" s32 func_0055CCF8(s32 arg0, s32 arg1);
extern "C" s32 func_00400CF0(s32 arg0);

extern "C" s32 func_00400D38(s32 arg0, s32 arg1) {
    return func_0055CCF8(arg0, func_00400CF0(arg1));
}
