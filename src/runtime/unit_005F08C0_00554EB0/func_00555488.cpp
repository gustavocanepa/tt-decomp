#include "types.h"

extern "C" void func_00567CF0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B8D0;

extern int D_00794E50;

extern "C" void *func_00555488(void) {
    if (D_00794E50 == 0) {
        func_00567CF0();
        func_0050C6E8(&D_00794E50, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B8D0);
    }
    return &D_00794E50;
}
