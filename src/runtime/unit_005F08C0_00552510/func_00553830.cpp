#include "types.h"

extern "C" void func_005535A0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794C00;

extern int D_00794C30;

extern "C" void *func_00553830(void) {
    if (D_00794C30 == 0) {
        func_005535A0();
        func_0050C6E8(&D_00794C30, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794C00);
    }
    return &D_00794C30;
}
