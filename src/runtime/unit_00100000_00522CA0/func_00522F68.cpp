#include "types.h"

extern "C" void func_00524A00();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005E84F0[];
extern int D_005E84F8;

extern int D_00793A40;

extern "C" void *func_00522F68(void) {
    if (D_00793A40 == 0) {
        func_00524A00();
        func_0050C6C0(&D_00793A40, D_005E84F0, &D_005E84F8, 1);
    }
    return &D_00793A40;
}
