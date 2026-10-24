#include "types.h"

extern "C" void func_00530FC8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00793E60;

extern int D_00793F40;

extern "C" void *func_00535C90(void) {
    if (D_00793F40 == 0) {
        func_00530FC8();
        func_0050C6E8(&D_00793F40, ((char *)"Q212GranTurismo413UpdateManager"), &D_00793E60);
    }
    return &D_00793F40;
}
