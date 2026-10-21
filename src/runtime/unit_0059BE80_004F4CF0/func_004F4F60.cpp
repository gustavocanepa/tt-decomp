#include "types.h"

extern s32 D_005A30A8;
extern "C" s32 func_004A47C0(s32 arg0, s32 arg1);

extern "C" s32 func_004F4F60(s32 arg0) {
    return func_004A47C0(D_005A30A8, arg0);
}
