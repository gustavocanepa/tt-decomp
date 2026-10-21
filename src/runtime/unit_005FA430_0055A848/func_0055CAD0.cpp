#include "types.h"

extern "C" void func_0051C5A0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B640;

extern int D_007953F0;

extern "C" void *func_0055CAD0(void) {
    if (D_007953F0 == 0) {
        func_0051C5A0();
        func_0050C6E8(&D_007953F0, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B640);
    }
    return &D_007953F0;
}
