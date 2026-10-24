#include "types.h"

extern "C" void func_005718F8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B9A8;

extern int D_007A5F40;

extern "C" void *func_005739B8(void) {
    if (D_007A5F40 == 0) {
        func_005718F8();
        func_0050C6E8(&D_007A5F40, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B9A8);
    }
    return &D_007A5F40;
}
