#include "types.h"

extern "C" void func_005658D0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795B30;

extern int D_00795B00;

extern "C" void *func_005657E0(void) {
    if (D_00795B00 == 0) {
        func_005658D0();
        func_0050C6E8(&D_00795B00, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795B30);
    }
    return &D_00795B00;
}
