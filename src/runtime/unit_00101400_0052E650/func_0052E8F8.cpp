#include "types.h"

extern "C" void func_0052FE98();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EAF78[];
extern int D_005EAF88;

extern int D_00793D80;

extern "C" void *func_0052E8F8(void) {
    if (D_00793D80 == 0) {
        func_0052FE98();
        func_0050C6C0(&D_00793D80, D_005EAF78, &D_005EAF88, 1);
    }
    return &D_00793D80;
}
