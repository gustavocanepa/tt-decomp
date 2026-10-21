#include "types.h"

extern "C" void func_00522DA0();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EC460[];
extern int D_005EC470;

extern int D_00793F30;

extern "C" void *func_00535BD0(void) {
    if (D_00793F30 == 0) {
        func_00522DA0();
        func_0050C6C0(&D_00793F30, D_005EC460, &D_005EC470, 1);
    }
    return &D_00793F30;
}
