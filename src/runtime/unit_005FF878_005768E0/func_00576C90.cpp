#include "types.h"

extern "C" void func_005769D8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_007A6480;

extern int D_007A64D0;

extern "C" void *func_00576C90(void) {
    if (D_007A64D0 == 0) {
        func_005769D8();
        func_0050C6E8(&D_007A64D0, ((char *)"Q212GranTurismo413UpdateManager"), &D_007A6480);
    }
    return &D_007A64D0;
}
