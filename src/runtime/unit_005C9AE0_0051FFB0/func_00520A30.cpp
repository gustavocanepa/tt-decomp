#include "types.h"

extern "C" void func_005206C0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B658;

extern int D_007938C0;

extern "C" void *func_00520A30(void) {
    if (D_007938C0 == 0) {
        func_005206C0();
        func_0050C6E8(&D_007938C0, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B658);
    }
    return &D_007938C0;
}
