#include "types.h"

extern "C" void func_0055DB28();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_007954B0;

extern int D_007952E0;

extern "C" void *func_0055A0E8(void) {
    if (D_007952E0 == 0) {
        func_0055DB28();
        func_0050C6E8(&D_007952E0, ((char *)"Q212GranTurismo413UpdateManager"), &D_007954B0);
    }
    return &D_007952E0;
}
