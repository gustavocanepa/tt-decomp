#include "types.h"

extern "C" void func_00522DA0();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005F05F0[];
extern int D_005F0600;

extern int D_00794540;

extern "C" void *func_005468C0(void) {
    if (D_00794540 == 0) {
        func_00522DA0();
        func_0050C6C0(&D_00794540, D_005F05F0, &D_005F0600, 1);
    }
    return &D_00794540;
}
