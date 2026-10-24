#include "types.h"

extern s32 D_00579F08;
extern s32 D_007641E8;

extern "C" s32 *func_0019A070(void) {
    if (D_00579F08 == 0) {
        D_00579F08 = 1;
        D_007641E8 = 0;
    }
    return &D_007641E8;
}
