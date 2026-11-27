#include "types.h"

extern "C" void func_0053F570();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EFA70[];
extern int D_005EFA88;

extern int D_00794430;

extern "C" void *func_005443D8(void) {
    if (D_00794430 == 0) {
        func_0053F570();
        func_0050C6C0(&D_00794430, D_005EFA70, &D_005EFA88, 1);
    }
    return &D_00794430;
}
