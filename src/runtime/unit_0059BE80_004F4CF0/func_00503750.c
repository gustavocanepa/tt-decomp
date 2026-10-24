#include "types.h"
s32 func_004FAC30(s32 a);
s32 func_00503750(void) {
    u32 r = func_004FAC30(4) & 0x10000;
    return r != 0;
}
