#include "types.h"

extern "C" void func_0052C9A0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00793D00;

extern int D_00793D10;

extern "C" void *func_0052CA70(void) {
    if (D_00793D10 == 0) {
        func_0052C9A0();
        func_0050C6E8(&D_00793D10, ((char *)"Q212GranTurismo413UpdateManager"), &D_00793D00);
    }
    return &D_00793D10;
}
