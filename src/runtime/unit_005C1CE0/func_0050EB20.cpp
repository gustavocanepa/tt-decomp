#include "types.h"

extern "C" void func_0050F058();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B600;

extern int D_007933A0;

extern "C" void *func_0050EB20(void) {
    if (D_007933A0 == 0) {
        func_0050F058();
        func_0050C6E8(&D_007933A0, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B600);
    }
    return &D_007933A0;
}
