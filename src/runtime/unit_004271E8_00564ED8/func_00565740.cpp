#include "types.h"

extern "C" void func_005631B0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795980;

extern int D_00795AD0;

extern "C" void *func_00565740(void) {
    if (D_00795AD0 == 0) {
        func_005631B0();
        func_0050C6E8(&D_00795AD0, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795980);
    }
    return &D_00795AD0;
}
