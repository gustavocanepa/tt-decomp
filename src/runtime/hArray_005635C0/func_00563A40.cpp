#include "types.h"

extern "C" void func_005635F0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_007959E0;

extern int D_00795A20;

extern "C" void *func_00563A40(void) {
    if (D_00795A20 == 0) {
        func_005635F0();
        func_0050C6E8(&D_00795A20, ((char *)"Q212GranTurismo413UpdateManager"), &D_007959E0);
    }
    return &D_00795A20;
}
