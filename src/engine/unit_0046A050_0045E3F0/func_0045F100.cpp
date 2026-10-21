#include "types.h"

extern "C" s32 func_0045F100(s32 arg0, u32 arg1) {
    if (arg1 >= 9u) {
        arg1 = 4u;
    }
    return *(s32 *)(0x603D38 + (arg1 * 4));
}
