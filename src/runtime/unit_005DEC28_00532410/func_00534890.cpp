#include "types.h"

extern "C" void func_00528908();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00793B80;

extern int D_00793EA0;

extern "C" void *func_00534890(void) {
    if (D_00793EA0 == 0) {
        func_00528908();
        func_0050C6E8(&D_00793EA0, ((char *)"Q212GranTurismo413UpdateManager"), &D_00793B80);
    }
    return &D_00793EA0;
}
