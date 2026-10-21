#include "types.h"

extern "C" s8 D_00582E70[8];

extern "C" s8 func_002ECEE0(s8 c) {
    s32 i;
    s8 r = c;
    for (i = 0; i < 8; i++) {
        if (D_00582E70[i] == c) {
            r = i;
            break;
        }
    }
    return r;
}
