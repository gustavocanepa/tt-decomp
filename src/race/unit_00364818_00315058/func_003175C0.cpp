#include "types.h"

extern "C" s32 func_003175C0(s32 arg0) {
    s32 v0 = arg0 + 1;
    if (arg0 > 0x7FFFFFFE) {
        v0 = arg0;
    }
    return v0;
}
