#include "types.h"

extern "C" void func_0056E9E8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795D28;

extern int D_00795BE0;

extern "C" void *func_00567D70(void) {
    if (D_00795BE0 == 0) {
        func_0056E9E8();
        func_0050C6E8(&D_00795BE0, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795D28);
    }
    return &D_00795BE0;
}
