#include "types.h"

extern "C" void func_00571EF0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B9D0;

extern int D_007A5E70;

extern "C" void *func_00571F30(void) {
    if (D_007A5E70 == 0) {
        func_00571EF0();
        func_0050C6E8(&D_007A5E70, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B9D0);
    }
    return &D_007A5E70;
}
