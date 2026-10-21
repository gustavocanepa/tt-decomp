#include "types.h"

extern "C" void func_005541A0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794D50;

extern int D_00794B60;

extern "C" void *func_00551160(void) {
    if (D_00794B60 == 0) {
        func_005541A0();
        func_0050C6E8(&D_00794B60, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794D50);
    }
    return &D_00794B60;
}
