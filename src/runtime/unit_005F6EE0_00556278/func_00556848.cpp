#include "types.h"

extern "C" void func_005564F8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B768;

extern int D_00794F70;

extern "C" void *func_00556848(void) {
    if (D_00794F70 == 0) {
        func_005564F8();
        func_0050C6E8(&D_00794F70, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B768);
    }
    return &D_00794F70;
}
