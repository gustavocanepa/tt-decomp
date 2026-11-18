#include "types.h"

extern "C" void func_0052A150();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00793C70;

extern int D_00793B30;

extern "C" void *func_005284F8(void) {
    if (D_00793B30 == 0) {
        func_0052A150();
        func_0050C6E8(&D_00793B30, ((char *)"Q212GranTurismo413UpdateManager"), &D_00793C70);
    }
    return &D_00793B30;
}
