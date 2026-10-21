#include "types.h"

extern "C" void func_0050F3C0();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00793480;

extern int D_00793980;

extern "C" void *func_00521CB8(void) {
    if (D_00793980 == 0) {
        func_0050F3C0();
        func_0050C6E8(&D_00793980, ((char *)"Q212GranTurismo413UpdateManager"), &D_00793480);
    }
    return &D_00793980;
}
