#include "types.h"

extern "C" void func_00546CB0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794560;

extern int D_007945B0;

extern "C" void *func_00546FF8(void) {
    if (D_007945B0 == 0) {
        func_00546CB0();
        func_0050C6E8(&D_007945B0, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794560);
    }
    return &D_007945B0;
}
