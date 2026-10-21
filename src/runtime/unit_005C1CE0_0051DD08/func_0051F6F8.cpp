#include "types.h"

extern "C" void func_0051EBC0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_007937D0;

extern int D_007937E0;

extern "C" void *func_0051F6F8(void) {
    if (D_007937E0 == 0) {
        func_0051EBC0();
        func_0050C6E8(&D_007937E0, ((char *)"Q212GranTurismo413UpdateManager"), &D_007937D0);
    }
    return &D_007937E0;
}
