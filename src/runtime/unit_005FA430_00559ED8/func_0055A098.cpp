#include "types.h"

extern "C" void func_0055DA90();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795490;

extern int D_007952F0;

extern "C" void *func_0055A098(void) {
    if (D_007952F0 == 0) {
        func_0055DA90();
        func_0050C6E8(&D_007952F0, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795490);
    }
    return &D_007952F0;
}
