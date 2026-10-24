#include "types.h"

extern "C" void func_00551078();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794B70;

extern int D_00795330;

extern "C" void *func_0055A5B8(void) {
    if (D_00795330 == 0) {
        func_00551078();
        func_0050C6E8(&D_00795330, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794B70);
    }
    return &D_00795330;
}
