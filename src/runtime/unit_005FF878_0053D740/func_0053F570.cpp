#include "types.h"

extern "C" void func_00522DA0();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EE3E8[];
extern int D_005EE3F8;

extern int D_00794240;

extern "C" void *func_0053F570(void) {
    if (D_00794240 == 0) {
        func_00522DA0();
        func_0050C6C0(&D_00794240, D_005EE3E8, &D_005EE3F8, 1);
    }
    return &D_00794240;
}
