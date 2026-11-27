#include "types.h"

extern "C" void func_00569F90();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B8F0;

extern int D_00795C00;

extern "C" void *func_0056BAF8(void) {
    if (D_00795C00 == 0) {
        func_00569F90();
        func_0050C6E8(&D_00795C00, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B8F0);
    }
    return &D_00795C00;
}
