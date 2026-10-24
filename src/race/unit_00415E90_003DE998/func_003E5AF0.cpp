#include "types.h"

extern s32 D_005F8F50[];

s32 func_003E5AF0(u32 arg0) {
    if (arg0 < 6U) {
        return D_005F8F50[arg0];
    }
    return -1;
}
