#include "types.h"

extern "C" void func_00571C88();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B9B0;

extern int D_007A5DA0;

extern "C" void *func_0056EFD0(void) {
    if (D_007A5DA0 == 0) {
        func_00571C88();
        func_0050C6E8(&D_007A5DA0, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B9B0);
    }
    return &D_007A5DA0;
}
