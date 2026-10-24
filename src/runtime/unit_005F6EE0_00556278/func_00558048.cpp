#include "types.h"

extern "C" void func_00556BD0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795070;

extern int D_00795030;

extern "C" void *func_00558048(void) {
    if (D_00795030 == 0) {
        func_00556BD0();
        func_0050C6E8(&D_00795030, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795070);
    }
    return &D_00795030;
}
