#include "types.h"

extern "C" void func_00563140();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B858;

extern int D_00795AE0;

extern "C" void *func_005656F0(void) {
    if (D_00795AE0 == 0) {
        func_00563140();
        func_0050C6E8(&D_00795AE0, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B858);
    }
    return &D_00795AE0;
}
