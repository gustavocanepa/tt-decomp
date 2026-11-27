#include "types.h"

extern "C" void func_0050F410();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B618;

extern int D_00793410;

extern "C" void *func_0050ED18(void) {
    if (D_00793410 == 0) {
        func_0050F410();
        func_0050C6E8(&D_00793410, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B618);
    }
    return &D_00793410;
}
