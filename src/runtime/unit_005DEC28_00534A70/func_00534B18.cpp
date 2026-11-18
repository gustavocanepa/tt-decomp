#include "types.h"

extern "C" void func_0053B058();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_007940C0;

extern int D_00793ED0;

extern "C" void *func_00534B18(void) {
    if (D_00793ED0 == 0) {
        func_0053B058();
        func_0050C6E8(&D_00793ED0, ((char *)"Q212GranTurismo413UpdateManager"), &D_007940C0);
    }
    return &D_00793ED0;
}
