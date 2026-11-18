#include "types.h"

extern "C" void func_0055B000();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B7C0;

extern int D_00794B10;

extern "C" void *func_00550858(void) {
    if (D_00794B10 == 0) {
        func_0055B000();
        func_0050C6E8(&D_00794B10, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B7C0);
    }
    return &D_00794B10;
}
