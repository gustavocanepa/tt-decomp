#include "types.h"

extern "C" void func_0056D1A0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795C20;

extern int D_00795760;

extern "C" void *func_00560720(void) {
    if (D_00795760 == 0) {
        func_0056D1A0();
        func_0050C6E8(&D_00795760, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795C20);
    }
    return &D_00795760;
}
