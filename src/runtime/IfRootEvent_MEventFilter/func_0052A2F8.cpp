#include "types.h"

extern "C" void func_0052A0D8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B6B0;

extern int D_00793C80;

extern "C" void *func_0052A2F8(void) {
    if (D_00793C80 == 0) {
        func_0052A0D8();
        func_0050C6E8(&D_00793C80, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B6B0);
    }
    return &D_00793C80;
}
