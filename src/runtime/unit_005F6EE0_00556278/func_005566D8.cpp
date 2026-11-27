#include "types.h"

extern "C" void func_005565F8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794F50;

extern int D_00794FA0;

extern "C" void *func_005566D8(void) {
    if (D_00794FA0 == 0) {
        func_005565F8();
        func_0050C6E8(&D_00794FA0, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794F50);
    }
    return &D_00794FA0;
}
