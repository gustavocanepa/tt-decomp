#include "types.h"

extern "C" void func_005718F8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B9A8;

extern int D_00795CD8;

extern "C" void *func_0056E020(void) {
    if (D_00795CD8 == 0) {
        func_005718F8();
        func_0050C6E8(&D_00795CD8, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B9A8);
    }
    return &D_00795CD8;
}
