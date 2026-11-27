#include "types.h"

extern "C" void func_00577468();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061BA40;

extern int D_007A64E0;

extern "C" void *func_00577650(void) {
    if (D_007A64E0 == 0) {
        func_00577468();
        func_0050C6E8(&D_007A64E0, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061BA40);
    }
    return &D_007A64E0;
}
