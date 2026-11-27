#include "types.h"

extern "C" void func_0055FE08();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B830;

extern int D_007956D0;

extern "C" void *func_0055F8C0(void) {
    if (D_007956D0 == 0) {
        func_0055FE08();
        func_0050C6E8(&D_007956D0, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B830);
    }
    return &D_007956D0;
}
