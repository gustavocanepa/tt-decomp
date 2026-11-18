#include "types.h"

extern "C" void func_0056ED50();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_007A5D80;

extern int D_007A5DB0;

extern "C" void *func_0056F070(void) {
    if (D_007A5DB0 == 0) {
        func_0056ED50();
        func_0050C6E8(&D_007A5DB0, ((char *)"Q212GranTurismo413UpdateManager"), &D_007A5D80);
    }
    return &D_007A5DB0;
}
