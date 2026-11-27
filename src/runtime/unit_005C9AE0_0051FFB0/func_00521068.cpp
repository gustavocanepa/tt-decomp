#include "types.h"

extern "C" void func_00520CA0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_007938A0;

extern int D_00793930;

extern "C" void *func_00521068(void) {
    if (D_00793930 == 0) {
        func_00520CA0();
        func_0050C6E8(&D_00793930, ((char *)"Q212GranTurismo413UpdateManager"), &D_007938A0);
    }
    return &D_00793930;
}
