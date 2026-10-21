#include "types.h"

extern "C" void func_00563580();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B868;

extern int D_00795A60;

extern "C" void *func_00564B00(void) {
    if (D_00795A60 == 0) {
        func_00563580();
        func_0050C6E8(&D_00795A60, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B868);
    }
    return &D_00795A60;
}
