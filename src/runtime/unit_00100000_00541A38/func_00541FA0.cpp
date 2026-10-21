#include "types.h"

extern "C" void func_00522DA0();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EEE78[];
extern int D_005EEE88;

extern int D_00794360;

extern "C" void *func_00541FA0(void) {
    if (D_00794360 == 0) {
        func_00522DA0();
        func_0050C6C0(&D_00794360, D_005EEE78, &D_005EEE88, 1);
    }
    return &D_00794360;
}
