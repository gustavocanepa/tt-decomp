#include "types.h"

extern "C" void func_00550120();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B6F0;

extern int D_00794320;

extern "C" void *func_00541968(void) {
    if (D_00794320 == 0) {
        func_00550120();
        func_0050C6E8(&D_00794320, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B6F0);
    }
    return &D_00794320;
}
