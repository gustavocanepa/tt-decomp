#include "types.h"

extern "C" void func_0050EB20();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_007933A0;

extern int D_00793480;

extern "C" void *func_0050F3C0(void) {
    if (D_00793480 == 0) {
        func_0050EB20();
        func_0050C6E8(&D_00793480, ((char *)"Q212GranTurismo413UpdateManager"), &D_007933A0);
    }
    return &D_00793480;
}
