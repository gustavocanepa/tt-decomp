#include "types.h"

extern "C" void func_00559F08();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_007952B0;

extern int D_007952C0;

extern "C" void *func_00559890(void) {
    if (D_007952C0 == 0) {
        func_00559F08();
        func_0050C6E8(&D_007952C0, ((char *)"Q212GranTurismo413UpdateManager"), &D_007952B0);
    }
    return &D_007952C0;
}
