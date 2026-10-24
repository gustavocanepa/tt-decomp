#include "types.h"

extern "C" s32 func_004AF490(s32 key, const u16 *table, s32 hi) {
    s32 lo = 0;
    do {
        s32 mid = (lo + hi) >> 1;
        if (key < table[mid])
            hi = mid;
        else
            lo = mid;
    } while (lo + 1 < hi);
    return lo;
}
