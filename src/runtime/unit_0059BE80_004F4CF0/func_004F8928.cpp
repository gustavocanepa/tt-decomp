#include "types.h"

extern "C" s32 D_005A30A8;
extern "C" s32 func_004F8948(s32 arg0, s32 arg1, s32 arg2);

extern "C" s32 func_004F8928(s32 arg0, s32 arg1) {
    return func_004F8948(arg0, arg1, D_005A30A8 + 0x5C);
}
