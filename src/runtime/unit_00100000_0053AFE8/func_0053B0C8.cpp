#include "types.h"

extern "C" void func_00522F68();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005ED1B0[];
extern int D_005ED1B8;

extern int D_007940D0;

extern "C" void *func_0053B0C8(void) {
    if (D_007940D0 == 0) {
        func_00522F68();
        func_0050C6C0(&D_007940D0, D_005ED1B0, &D_005ED1B8, 1);
    }
    return &D_007940D0;
}
