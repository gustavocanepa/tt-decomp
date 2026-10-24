#include "types.h"

extern "C" s32 func_0019A030(void *a0);

extern char D_007641C0[];

extern s32 D_00579F04;

extern "C" void *func_00199FD8(void) {
    if (D_00579F04 == 0) {
        s32 t = func_0019A030(D_007641C0);
        D_00579F04 = 1;
        (void)t;
    }
    return D_007641C0;
}
