#include "types.h"

extern "C" void func_00552840();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B728;

extern int D_00794BC0;

extern "C" void *func_005527F0(void) {
    if (D_00794BC0 == 0) {
        func_00552840();
        func_0050C6E8(&D_00794BC0, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B728);
    }
    return &D_00794BC0;
}
