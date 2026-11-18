#include "types.h"

extern "C" void func_00571AA8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_007A5E60;

extern int D_007933E0;

extern "C" void *func_0050EBD8(void) {
    if (D_007933E0 == 0) {
        func_00571AA8();
        func_0050C6E8(&D_007933E0, ((char *)"Q212GranTurismo413UpdateManager"), &D_007A5E60);
    }
    return &D_007933E0;
}
