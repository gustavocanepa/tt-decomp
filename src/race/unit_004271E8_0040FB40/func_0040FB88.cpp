#include "types.h"

extern char D_00585A30[];
extern "C" s32 func_0040B840(void *arg0, s32 arg1, s32 arg2);

extern "C" s32 func_0040FB88(s32 arg0) {
    return func_0040B840(D_00585A30, arg0, 0);
}
