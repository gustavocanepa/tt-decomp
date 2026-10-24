#include "types.h"

extern "C" void func_00552F10();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794BE0;

extern int D_00794B40;

extern "C" void *func_00550AD0(void) {
    if (D_00794B40 == 0) {
        func_00552F10();
        func_0050C6E8(&D_00794B40, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794BE0);
    }
    return &D_00794B40;
}
