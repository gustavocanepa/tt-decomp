#include "types.h"

extern "C" void func_00553FB0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B740;

extern int D_00795650;

extern "C" void *func_0055F320(void) {
    if (D_00795650 == 0) {
        func_00553FB0();
        func_0050C6E8(&D_00795650, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B740);
    }
    return &D_00795650;
}
