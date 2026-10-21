#include "types.h"

extern "C" void func_00526A50();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_0061B690;

extern int D_00793D60;

extern "C" void *func_0052DD08(void) {
    if (D_00793D60 == 0) {
        func_00526A50();
        func_0050C6E8(&D_00793D60, ((char *)"Q212GranTurismo413UpdateManager"), &D_0061B690);
    }
    return &D_00793D60;
}
