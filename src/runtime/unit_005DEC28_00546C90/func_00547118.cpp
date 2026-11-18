#include "types.h"

extern "C" void func_00522F68();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005F09F0[];
extern int D_005F09F8;

extern int D_007945C0;

extern "C" void *func_00547118(void) {
    if (D_007945C0 == 0) {
        func_00522F68();
        func_0050C6C0(&D_007945C0, D_005F09F0, &D_005F09F8, 1);
    }
    return &D_007945C0;
}
