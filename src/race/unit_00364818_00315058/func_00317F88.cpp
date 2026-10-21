#include "types.h"

extern "C" s32 func_00317F88(s32 arg0) {
    if (arg0 < 0) {
        arg0 = 0;
    }
    if (arg0 >= 0x13) {
        arg0 = 0x12;
    }
    return *(s32 *)(0x583A90 + (arg0 * 4));
}
