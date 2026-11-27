#include "types.h"

extern "C" void func_00522F68();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EEDD0[];
extern int D_005EEDD8;

extern int D_00794350;

extern "C" void *func_00541DC8(void) {
    if (D_00794350 == 0) {
        func_00522F68();
        func_0050C6C0(&D_00794350, D_005EEDD0, &D_005EEDD8, 1);
    }
    return &D_00794350;
}
