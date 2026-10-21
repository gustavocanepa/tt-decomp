#include "types.h"

extern "C" void func_005442B0();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EF688[];
extern int D_005EF698;

extern int D_007943C0;

extern "C" void *func_00543660(void) {
    if (D_007943C0 == 0) {
        func_005442B0();
        func_0050C6C0(&D_007943C0, D_005EF688, &D_005EF698, 1);
    }
    return &D_007943C0;
}
