#include "types.h"

extern "C" void func_0050F450();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00793490;

extern int D_007933F0;

extern "C" void *func_0050EC80(void) {
    if (D_007933F0 == 0) {
        func_0050F450();
        func_0050C6E8(&D_007933F0, ((char *)"Q212GranTurismo413UpdateManager"), &D_00793490);
    }
    return &D_007933F0;
}
