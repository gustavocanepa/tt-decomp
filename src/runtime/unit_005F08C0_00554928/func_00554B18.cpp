#include "types.h"

extern "C" void func_00554AC0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794DA0;

extern int D_00794D80;

extern "C" void *func_00554B18(void) {
    if (D_00794D80 == 0) {
        func_00554AC0();
        func_0050C6E8(&D_00794D80, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794DA0);
    }
    return &D_00794D80;
}
