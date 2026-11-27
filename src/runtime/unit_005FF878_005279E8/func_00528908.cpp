#include "types.h"

extern "C" void func_005386F8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794080;

extern int D_00793B80;

extern "C" void *func_00528908(void) {
    if (D_00793B80 == 0) {
        func_005386F8();
        func_0050C6E8(&D_00793B80, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794080);
    }
    return &D_00793B80;
}
