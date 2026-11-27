#include "types.h"

extern "C" void func_00535C90();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00793F40;

extern int D_00793F60;

extern "C" void *func_00535F40(void) {
    if (D_00793F60 == 0) {
        func_00535C90();
        func_0050C6E8(&D_00793F60, ((char *)"Q212GranTurismo413UpdateManager"), &D_00793F40);
    }
    return &D_00793F60;
}
