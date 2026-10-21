#include "types.h"

extern "C" void func_00554688();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794D70;

extern int D_007954B0;

extern "C" void *func_0055DB28(void) {
    if (D_007954B0 == 0) {
        func_00554688();
        func_0050C6E8(&D_007954B0, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794D70);
    }
    return &D_007954B0;
}
