#include "types.h"

extern "C" void func_005677D8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B8C8;

extern int D_00795B90;

extern "C" void *func_00566BD0(void) {
    if (D_00795B90 == 0) {
        func_005677D8();
        func_0050C6E8(&D_00795B90, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B8C8);
    }
    return &D_00795B90;
}
