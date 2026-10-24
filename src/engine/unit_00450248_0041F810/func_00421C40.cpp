#include "types.h"

extern s32 D_00585D34;

extern "C" s32 func_00421C40(s32 arg0) {
    s32 temp_v0 = D_00585D34;
    D_00585D34 = arg0;
    return temp_v0;
}
