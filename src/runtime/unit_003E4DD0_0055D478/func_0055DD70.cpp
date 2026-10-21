#include "types.h"

extern "C" void func_0055DD10();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_007954F0;

extern int D_007954D0;

extern "C" void *func_0055DD70(void) {
    if (D_007954D0 == 0) {
        func_0055DD10();
        func_0050C6E8(&D_007954D0, ((char *)"Q212GranTurismo413UpdateManager"), &D_007954F0);
    }
    return &D_007954D0;
}
