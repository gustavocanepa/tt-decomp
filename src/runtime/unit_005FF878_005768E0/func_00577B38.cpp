#include "types.h"

extern "C" void func_00578548();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061BA58;

extern int D_007A6900;

extern "C" void *func_00577B38(void) {
    if (D_007A6900 == 0) {
        func_00578548();
        func_0050C6E8(&D_007A6900, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061BA58);
    }
    return &D_007A6900;
}
