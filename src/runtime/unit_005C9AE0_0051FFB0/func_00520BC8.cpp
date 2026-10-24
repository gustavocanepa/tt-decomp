#include "types.h"

extern "C" void func_00520B08();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00793900;

extern int D_007938D0;

extern "C" void *func_00520BC8(void) {
    if (D_007938D0 == 0) {
        func_00520B08();
        func_0050C6E8(&D_007938D0, ((char *)"Q212GranTurismo413UpdateManager"), &D_00793900);
    }
    return &D_007938D0;
}
