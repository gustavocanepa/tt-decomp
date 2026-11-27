#include "types.h"

extern "C" void func_00564B00();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795A60;

extern int D_00795A90;

extern "C" void *func_00565440(void) {
    if (D_00795A90 == 0) {
        func_00564B00();
        func_0050C6E8(&D_00795A90, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795A60);
    }
    return &D_00795A90;
}
