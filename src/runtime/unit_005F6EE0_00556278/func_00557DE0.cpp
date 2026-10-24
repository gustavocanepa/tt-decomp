#include "types.h"

extern "C" void func_00556BD0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795070;

extern int D_00794FF0;

extern "C" void *func_00557DE0(void) {
    if (D_00794FF0 == 0) {
        func_00556BD0();
        func_0050C6E8(&D_00794FF0, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795070);
    }
    return &D_00794FF0;
}
