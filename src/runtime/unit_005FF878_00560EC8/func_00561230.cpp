#include "types.h"

extern "C" void func_00561120();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795860;

extern int D_007958A0;

extern "C" void *func_00561230(void) {
    if (D_007958A0 == 0) {
        func_00561120();
        func_0050C6E8(&D_007958A0, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795860);
    }
    return &D_007958A0;
}
