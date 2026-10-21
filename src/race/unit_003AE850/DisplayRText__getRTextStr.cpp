#include "types.h"

extern char D_00584428[];
extern s32 D_00584430;

extern "C" s32 func_0044CD98(void *arg0, s32 arg1, s32 arg2);

extern "C" s32 DisplayRText__getRTextStr(s32 arg0) {
    return func_0044CD98(D_00584428, D_00584430, arg0);
}
