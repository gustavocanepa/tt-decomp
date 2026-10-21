#include "types.h"

extern "C" void func_00552F80();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794BF0;

extern int D_00794C80;

extern "C" void *func_00553A40(void) {
    if (D_00794C80 == 0) {
        func_00552F80();
        func_0050C6E8(&D_00794C80, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794BF0);
    }
    return &D_00794C80;
}
