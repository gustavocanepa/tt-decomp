#include "types.h"

extern "C" void func_00560AB8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B850;

extern int D_00795830;

extern "C" void *func_00560E18(void) {
    if (D_00795830 == 0) {
        func_00560AB8();
        func_0050C6E8(&D_00795830, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B850);
    }
    return &D_00795830;
}
