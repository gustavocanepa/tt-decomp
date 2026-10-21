#include "types.h"

extern "C" void func_00553920();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794C60;

extern int D_00794C50;

extern "C" void *func_00553980(void) {
    if (D_00794C50 == 0) {
        func_00553920();
        func_0050C6E8(&D_00794C50, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794C60);
    }
    return &D_00794C50;
}
