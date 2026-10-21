#include "types.h"

extern "C" void func_00577CD0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_007A6910;

extern int D_007A6930;

extern "C" void *func_00577F28(void) {
    if (D_007A6930 == 0) {
        func_00577CD0();
        func_0050C6E8(&D_007A6930, ((char *)"Q212GranTurismo413UpdateManager"), &D_007A6910);
    }
    return &D_007A6930;
}
