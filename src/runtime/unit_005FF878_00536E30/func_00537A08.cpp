#include "types.h"

extern "C" void func_0053F570();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005ECC40[];
extern int D_005ECC58;

extern int D_00794000;

extern "C" void *func_00537A08(void) {
    if (D_00794000 == 0) {
        func_0053F570();
        func_0050C6C0(&D_00794000, D_005ECC40, &D_005ECC58, 1);
    }
    return &D_00794000;
}
