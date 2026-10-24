#include "types.h"

extern "C" void func_00574C58();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061BA10;

extern int D_00795740;

extern "C" void *func_00560200(void) {
    if (D_00795740 == 0) {
        func_00574C58();
        func_0050C6E8(&D_00795740, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061BA10);
    }
    return &D_00795740;
}
