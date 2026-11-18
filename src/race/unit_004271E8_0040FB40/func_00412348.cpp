#include "types.h"

extern "C" s32 func_00412348(s32 arg0) {
    s32 var_v0;

    if (arg0 == 0x14) {
        goto ret1;
    }
    if (arg0 != 0x16) {
        var_v0 = 0;
        return var_v0;
    }
ret1:
    var_v0 = 1;
    return var_v0;
}
