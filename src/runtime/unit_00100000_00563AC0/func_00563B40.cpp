#include "types.h"

extern "C" void func_005618A0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_007958E0;

extern int D_00795A10;

extern "C" void *func_00563B40(void) {
    if (D_00795A10 == 0) {
        func_005618A0();
        func_0050C6E8(&D_00795A10, ((char *)"Q212GranTurismo413UpdateManager"), &D_007958E0);
    }
    return &D_00795A10;
}
