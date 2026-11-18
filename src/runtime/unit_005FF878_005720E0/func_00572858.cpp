#include "types.h"

extern "C" void func_005773E8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061BA38;

extern int D_007A5EE0;

extern "C" void *func_00572858(void) {
    if (D_007A5EE0 == 0) {
        func_005773E8();
        func_0050C6E8(&D_007A5EE0, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061BA38);
    }
    return &D_007A5EE0;
}
