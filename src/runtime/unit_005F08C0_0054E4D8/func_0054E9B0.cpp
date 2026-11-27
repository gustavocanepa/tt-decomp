#include "types.h"

extern "C" void func_0054A7D8();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794690;

extern int D_00794820;

extern "C" void *func_0054E9B0(void) {
    if (D_00794820 == 0) {
        func_0054A7D8();
        func_0050C6E8(&D_00794820, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794690);
    }
    return &D_00794820;
}
