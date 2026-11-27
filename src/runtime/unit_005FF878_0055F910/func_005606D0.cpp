#include "types.h"

extern "C" void func_0056D150();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795C30;

extern int D_007957B0;

extern "C" void *func_005606D0(void) {
    if (D_007957B0 == 0) {
        func_0056D150();
        func_0050C6E8(&D_007957B0, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795C30);
    }
    return &D_007957B0;
}
