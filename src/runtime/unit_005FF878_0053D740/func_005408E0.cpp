#include "types.h"

extern "C" void func_00511F38();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B628;

extern int D_00794270;

extern "C" void *func_005408E0(void) {
    if (D_00794270 == 0) {
        func_00511F38();
        func_0050C6E8(&D_00794270, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B628);
    }
    return &D_00794270;
}
