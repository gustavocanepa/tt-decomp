#include "types.h"

extern "C" void func_00524A00();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EFB48[];
extern int D_005EFB58;

extern int D_00794450;

extern "C" void *func_00544AB0(void) {
    if (D_00794450 == 0) {
        func_00524A00();
        func_0050C6C0(&D_00794450, D_005EFB48, &D_005EFB58, 1);
    }
    return &D_00794450;
}
