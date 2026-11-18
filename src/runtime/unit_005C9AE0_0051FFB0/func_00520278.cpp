#include "types.h"

extern "C" void func_00520050();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00793870;

extern int D_00793840;

extern "C" void *func_00520278(void) {
    if (D_00793840 == 0) {
        func_00520050();
        func_0050C6E8(&D_00793840, ((char *)"Q212GranTurismo413UpdateManager"), &D_00793870);
    }
    return &D_00793840;
}
