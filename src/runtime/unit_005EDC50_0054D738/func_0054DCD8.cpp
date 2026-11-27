#include "types.h"

extern "C" void func_0054B918();
extern "C" void func_0050C6E8(void *a0, void *a1, void *a2);

extern int D_00794700;

extern int D_00794770;

extern "C" void *func_0054DCD8(void) {
    if (D_00794770 == 0) {
        func_0054B918();
        func_0050C6E8(&D_00794770, ((char *)"Q212GranTurismo413UpdateManager"), &D_00794700);
    }
    return &D_00794770;
}
