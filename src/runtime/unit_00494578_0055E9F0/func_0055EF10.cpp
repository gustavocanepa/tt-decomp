#include "types.h"

extern "C" void func_0055EFD0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00795630;

extern int D_00795620;

extern "C" void *func_0055EF10(void) {
    if (D_00795620 == 0) {
        func_0055EFD0();
        func_0050C6E8(&D_00795620, ((char *)"Q212GranTurismo413UpdateManager"), &D_00795630);
    }
    return &D_00795620;
}
