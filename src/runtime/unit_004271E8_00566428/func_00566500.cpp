#include "types.h"

extern "C" void func_005665A0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B8B8;

extern int D_00795B50;

extern "C" void *func_00566500(void) {
    if (D_00795B50 == 0) {
        func_005665A0();
        func_0050C6E8(&D_00795B50, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B8B8);
    }
    return &D_00795B50;
}
