#include "types.h"

extern "C" f32 func_00317FD8(s32 arg0) {
    s32 idx = arg0;
    if (idx <= 0) {
        idx = 0;
    }
    if (idx >= 0xB) {
        idx = 0xB;
    }
    return *(f32 *)(0x583B38 + idx * 4);
}
