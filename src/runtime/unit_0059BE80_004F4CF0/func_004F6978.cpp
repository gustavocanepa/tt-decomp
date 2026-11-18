#include "types.h"

extern s32 D_005A30A8;
extern "C" s32 func_004F68F0(s32 arg0, s32 arg1);

extern "C" s32 func_004F6978(s32 arg0) {
    return func_004F68F0(D_005A30A8, arg0);
}
