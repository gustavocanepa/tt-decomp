#include "types.h"

extern "C" void func_0056E568();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795CE8;

extern int D_0079DD50;

extern "C" void *func_0056EC30(void) {
    if (D_0079DD50 == 0) {
        func_0056E568();
        func_0050C6E8(&D_0079DD50, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795CE8);
    }
    return &D_0079DD50;
}
