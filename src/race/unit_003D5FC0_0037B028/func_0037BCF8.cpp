#include "types.h"

extern "C" s32 func_0037BCF8(u32 *p, u32 v) {
    u32 cur = *p;
    if (cur == 0x157529FF || v < cur) {
        if (v > 0x157529FF) v = 0x157529FF;
        *p = v;
        return 1;
    }
    return 0;
}
