#include "types.h"

extern "C" void func_00524A00();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EE8F8[];
extern int D_005EE908;

extern int D_007942E0;

extern "C" void *func_005410D0(void) {
    if (D_007942E0 == 0) {
        func_00524A00();
        func_0050C6C0(&D_007942E0, D_005EE8F8, &D_005EE908, 1);
    }
    return &D_007942E0;
}
