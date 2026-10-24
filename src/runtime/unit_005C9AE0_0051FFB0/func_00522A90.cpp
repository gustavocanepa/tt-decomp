#include "types.h"

extern "C" void func_00522768();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B680;

extern int D_007939E0;

extern "C" void *func_00522A90(void) {
    if (D_007939E0 == 0) {
        func_00522768();
        func_0050C6E8(&D_007939E0, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B680);
    }
    return &D_007939E0;
}
