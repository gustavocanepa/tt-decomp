#include "types.h"

extern "C" s32 D_005A0DE0;
extern "C" s32 D_005A1F40;

extern "C" s32 func_004E03F8(void) {
    if (D_005A0DE0 == 1) {
        return *(s32 *)((u32)&D_005A1F40 | 0x20000000);
    }
    return 0;
}
