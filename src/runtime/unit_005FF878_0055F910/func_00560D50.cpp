#include "types.h"

extern "C" void func_00561188();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795880;

extern int D_00795810;

extern "C" void *func_00560D50(void) {
    if (D_00795810 == 0) {
        func_00561188();
        func_0050C6E8(&D_00795810, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795880);
    }
    return &D_00795810;
}
