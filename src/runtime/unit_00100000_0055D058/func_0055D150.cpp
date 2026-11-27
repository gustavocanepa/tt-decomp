#include "types.h"

extern "C" void func_0055CE70();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795450;

extern int D_00795480;

extern "C" void *func_0055D150(void) {
    if (D_00795480 == 0) {
        func_0055CE70();
        func_0050C6E8(&D_00795480, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795450);
    }
    return &D_00795480;
}
