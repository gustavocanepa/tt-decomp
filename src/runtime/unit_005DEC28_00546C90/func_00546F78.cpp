#include "types.h"

extern "C" void func_0054D6E8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794750;

extern int D_007945A0;

extern "C" void *func_00546F78(void) {
    if (D_007945A0 == 0) {
        func_0054D6E8();
        func_0050C6E8(&D_007945A0, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794750);
    }
    return &D_007945A0;
}
