#include "types.h"

extern "C" void func_00571F30();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_007A5E70;

extern int D_00795CE8;

extern "C" void *func_0056E568(void) {
    if (D_00795CE8 == 0) {
        func_00571F30();
        func_0050C6E8(&D_00795CE8, ((char *)"Q212GranTurismo413UpdateManager"), &D_007A5E70);
    }
    return &D_00795CE8;
}
