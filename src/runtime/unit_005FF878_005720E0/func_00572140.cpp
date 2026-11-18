#include "types.h"

extern "C" void func_005711D0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B998;

extern int D_007A5E90;

extern "C" void *func_00572140(void) {
    if (D_007A5E90 == 0) {
        func_005711D0();
        func_0050C6E8(&D_007A5E90, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B998);
    }
    return &D_007A5E90;
}
