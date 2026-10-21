#include "types.h"

extern "C" void func_0051CAF0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B648;

extern int D_007939A0;

extern "C" void *func_00521ED0(void) {
    if (D_007939A0 == 0) {
        func_0051CAF0();
        func_0050C6E8(&D_007939A0, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B648);
    }
    return &D_007939A0;
}
