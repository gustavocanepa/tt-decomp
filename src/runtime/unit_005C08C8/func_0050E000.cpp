#include "types.h"

extern s32 D_005A4848;

extern "C" s32 func_0050E000(s32 arg0) {
    s32 temp_v0 = D_005A4848;
    D_005A4848 = arg0;
    return temp_v0;
}
