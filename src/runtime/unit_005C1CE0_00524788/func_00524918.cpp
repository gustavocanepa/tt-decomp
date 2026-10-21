#include "types.h"

extern "C" void func_00529A90();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B6A8;

extern int D_00793AC0;

extern "C" void *func_00524918(void) {
    if (D_00793AC0 == 0) {
        func_00529A90();
        func_0050C6E8(&D_00793AC0, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B6A8);
    }
    return &D_00793AC0;
}
