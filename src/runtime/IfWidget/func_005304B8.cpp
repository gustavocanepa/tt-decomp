#include "types.h"

extern "C" void func_005305D0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00793E10;

extern int D_00793E40;

extern "C" void *func_005304B8(void) {
    if (D_00793E40 == 0) {
        func_005305D0();
        func_0050C6E8(&D_00793E40, ((char *)"Q212GranTurismo413UpdateManager"), &D_00793E10);
    }
    return &D_00793E40;
}
