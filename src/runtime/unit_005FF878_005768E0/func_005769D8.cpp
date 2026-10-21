#include "types.h"

extern "C" void func_00576400();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_007A6490;

extern int D_007A6480;

extern "C" void *func_005769D8(void) {
    if (D_007A6480 == 0) {
        func_00576400();
        func_0050C6E8(&D_007A6480, ((char *)"Q212GranTurismo413UpdateManager"), &D_007A6490);
    }
    return &D_007A6480;
}
