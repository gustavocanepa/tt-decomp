#include "types.h"

extern "C" void func_00554F80();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794DE0;

extern int D_00794E10;

extern "C" void *func_00554D18(void) {
    if (D_00794E10 == 0) {
        func_00554F80();
        func_0050C6E8(&D_00794E10, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794DE0);
    }
    return &D_00794E10;
}
