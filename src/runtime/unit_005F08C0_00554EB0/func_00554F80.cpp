#include "types.h"

extern "C" void func_00522118();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B678;

extern int D_00794DE0;

extern "C" void *func_00554F80(void) {
    if (D_00794DE0 == 0) {
        func_00522118();
        func_0050C6E8(&D_00794DE0, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B678);
    }
    return &D_00794DE0;
}
