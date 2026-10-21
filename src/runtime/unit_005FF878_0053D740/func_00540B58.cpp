#include "types.h"

extern "C" void func_00530FC8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00793E60;

extern int D_007942A0;

extern "C" void *func_00540B58(void) {
    if (D_007942A0 == 0) {
        func_00530FC8();
        func_0050C6E8(&D_007942A0, ((char *)"Q212GranTurismo413UpdateManager"), &D_00793E60);
    }
    return &D_007942A0;
}
