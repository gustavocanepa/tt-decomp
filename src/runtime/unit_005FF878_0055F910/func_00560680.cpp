#include "types.h"

extern "C" void func_0056D0B0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B900;

extern int D_007957A0;

extern "C" void *func_00560680(void) {
    if (D_007957A0 == 0) {
        func_0056D0B0();
        func_0050C6E8(&D_007957A0, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B900);
    }
    return &D_007957A0;
}
