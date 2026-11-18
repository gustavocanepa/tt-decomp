#include "types.h"

extern "C" void func_005727E0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B9E0;

extern int D_007A5EA0;

extern "C" void *func_00572398(void) {
    if (D_007A5EA0 == 0) {
        func_005727E0();
        func_0050C6E8(&D_007A5EA0, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B9E0);
    }
    return &D_007A5EA0;
}
