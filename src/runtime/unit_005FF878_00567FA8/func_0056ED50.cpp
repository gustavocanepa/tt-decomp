#include "types.h"

extern "C" void func_0056E070();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B978;

extern int D_007A5D80;

extern "C" void *func_0056ED50(void) {
    if (D_007A5D80 == 0) {
        func_0056E070();
        func_0050C6E8(&D_007A5D80, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B978);
    }
    return &D_007A5D80;
}
