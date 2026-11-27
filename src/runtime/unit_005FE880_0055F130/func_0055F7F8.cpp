#include "types.h"

extern "C" void func_005677D8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B8C8;

extern int D_007956B0;

extern "C" void *func_0055F7F8(void) {
    if (D_007956B0 == 0) {
        func_005677D8();
        func_0050C6E8(&D_007956B0, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B8C8);
    }
    return &D_007956B0;
}
