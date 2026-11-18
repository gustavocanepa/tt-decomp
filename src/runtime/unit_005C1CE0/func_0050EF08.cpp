#include "types.h"

extern "C" void func_0050ED18();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00793410;

extern int D_00793460;

extern "C" void *func_0050EF08(void) {
    if (D_00793460 == 0) {
        func_0050ED18();
        func_0050C6E8(&D_00793460, ((char *)"Q212GranTurismo413UpdateManager"), &D_00793410);
    }
    return &D_00793460;
}
