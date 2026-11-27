#include "types.h"

extern "C" void func_0056DC38();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B970;

extern int D_00795CA8;

extern "C" void *func_0056DF10(void) {
    if (D_00795CA8 == 0) {
        func_0056DC38();
        func_0050C6E8(&D_00795CA8, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B970);
    }
    return &D_00795CA8;
}
