#include "types.h"

extern "C" void func_00571310();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B9A0;

extern int D_007A5E50;

extern "C" void *func_005713A0(void) {
    if (D_007A5E50 == 0) {
        func_00571310();
        func_0050C6E8(&D_007A5E50, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B9A0);
    }
    return &D_007A5E50;
}
