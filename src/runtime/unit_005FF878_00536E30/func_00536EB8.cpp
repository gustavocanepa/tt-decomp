#include "types.h"

extern "C" void func_00537020();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00793FE0;

extern int D_00793FB0;

extern "C" void *func_00536EB8(void) {
    if (D_00793FB0 == 0) {
        func_00537020();
        func_0050C6E8(&D_00793FB0, ((char *)"Q212GranTurismo413UpdateManager"), &D_00793FE0);
    }
    return &D_00793FB0;
}
