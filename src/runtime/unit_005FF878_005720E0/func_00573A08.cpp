#include "types.h"

extern "C" void func_00575060();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061BA18;

extern int D_007A6360;

extern "C" void *func_00573A08(void) {
    if (D_007A6360 == 0) {
        func_00575060();
        func_0050C6E8(&D_007A6360, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061BA18);
    }
    return &D_007A6360;
}
