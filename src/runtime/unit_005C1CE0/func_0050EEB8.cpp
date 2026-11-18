#include "types.h"

extern "C" void func_0050ED70();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00793420;

extern int D_00793400;

extern "C" void *func_0050EEB8(void) {
    if (D_00793400 == 0) {
        func_0050ED70();
        func_0050C6E8(&D_00793400, ((char *)"Q212GranTurismo413UpdateManager"), &D_00793420);
    }
    return &D_00793400;
}
