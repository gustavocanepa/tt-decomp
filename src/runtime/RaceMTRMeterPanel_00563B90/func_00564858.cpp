#include "types.h"

extern "C" void func_00561FB8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795940;

extern int D_00795A50;

extern "C" void *func_00564858(void) {
    if (D_00795A50 == 0) {
        func_00561FB8();
        func_0050C6E8(&D_00795A50, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795940);
    }
    return &D_00795A50;
}
