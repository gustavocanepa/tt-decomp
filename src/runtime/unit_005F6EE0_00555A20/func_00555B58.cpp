#include "types.h"

extern "C" void func_00567E00();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B8E0;

extern int D_00794EC0;

extern "C" void *func_00555B58(void) {
    if (D_00794EC0 == 0) {
        func_00567E00();
        func_0050C6E8(&D_00794EC0, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B8E0);
    }
    return &D_00794EC0;
}
