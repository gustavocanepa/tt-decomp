#include "types.h"

extern "C" void func_00576C10();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061BA28;

extern int D_007A64A0;

extern "C" void *func_005761C0(void) {
    if (D_007A64A0 == 0) {
        func_00576C10();
        func_0050C6E8(&D_007A64A0, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061BA28);
    }
    return &D_007A64A0;
}
