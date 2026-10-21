#include "types.h"

extern "C" void func_00526B58();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00793B00;

extern int D_00793E90;

extern "C" void *func_00534838(void) {
    if (D_00793E90 == 0) {
        func_00526B58();
        func_0050C6E8(&D_00793E90, ((char *)"Q212GranTurismo413UpdateManager"), &D_00793B00);
    }
    return &D_00793E90;
}
