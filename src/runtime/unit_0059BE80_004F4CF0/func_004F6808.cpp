#include "types.h"

extern s32 D_005A30A8;
extern "C" s32 func_004F6798(s32 arg0, s32 arg1);

extern "C" s32 func_004F6808(s32 arg0) {
    return func_004F6798(D_005A30A8, arg0);
}
