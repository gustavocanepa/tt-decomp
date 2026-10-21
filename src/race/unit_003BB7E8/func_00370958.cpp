#include "types.h"

extern "C" s32 func_003709A0(s32 arg0, s32 arg1, s32 arg2);

extern "C" s32 func_00370958(void *arg0, void *arg1, s32 arg2) {
    s32 off = arg2 * 4;
    s32 v1 = *(s32 *)((char *)arg1 + off);
    s32 v0 = *(s32 *)((char *)arg0 + off);
    return func_003709A0(v0, v1, off);
}
