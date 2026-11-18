#include "types.h"

extern "C" void func_00518360();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B630;

extern int D_00793560;

extern "C" void *func_00518548(void) {
    if (D_00793560 == 0) {
        func_00518360();
        func_0050C6E8(&D_00793560, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B630);
    }
    return &D_00793560;
}
