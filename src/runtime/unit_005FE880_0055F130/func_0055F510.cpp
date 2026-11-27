#include "types.h"

extern "C" void func_0055C980();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B7C8;

extern int D_007956A0;

extern "C" void *func_0055F510(void) {
    if (D_007956A0 == 0) {
        func_0055C980();
        func_0050C6E8(&D_007956A0, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B7C8);
    }
    return &D_007956A0;
}
