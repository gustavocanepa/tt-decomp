#include "types.h"

extern "C" void func_0050EC28();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_007933C0;

extern int D_007933D0;

extern "C" void *func_0050EAD0(void) {
    if (D_007933D0 == 0) {
        func_0050EC28();
        func_0050C6E8(&D_007933D0, ((char *)"Q212GranTurismo413UpdateManager"), &D_007933C0);
    }
    return &D_007933D0;
}
