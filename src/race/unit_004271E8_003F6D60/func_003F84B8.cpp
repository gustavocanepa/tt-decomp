#include "types.h"
extern "C" u64 func_003F84B8(const u8 *field, u8 limit) {
    u64 threshold = (u64)*field >> 4;
    if (threshold == 15) return 0;
    u64 below = limit < threshold;
    return below ^ 1;
}
