#include "types.h"

extern "C" void func_005592E0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795190;

extern int D_00794FD0;

extern "C" void *func_005593C0(void) {
    if (D_00794FD0 == 0) {
        func_005592E0();
        func_0050C6E8(&D_00794FD0, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795190);
    }
    return &D_00794FD0;
}
