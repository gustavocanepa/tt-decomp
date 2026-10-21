#include "types.h"

extern "C" void func_00524A00();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005E9B50[];
extern int D_005E9B60;

extern int D_00793C40;

extern "C" void *func_00529D50(void) {
    if (D_00793C40 == 0) {
        func_00524A00();
        func_0050C6C0(&D_00793C40, D_005E9B50, &D_005E9B60, 1);
    }
    return &D_00793C40;
}
