#include "types.h"

extern s32 D_005F8F10[];

s32 func_003E5A90(u32 arg0) {
    if (arg0 < 7U) {
        return D_005F8F10[arg0];
    }
    return -1;
}
