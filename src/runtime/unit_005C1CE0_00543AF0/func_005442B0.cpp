#include "types.h"

extern "C" void func_00522F68();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EF978[];
extern int D_005EF980;

extern int D_00794420;

extern "C" void *func_005442B0(void) {
    if (D_00794420 == 0) {
        func_00522F68();
        func_0050C6C0(&D_00794420, D_005EF978, &D_005EF980, 1);
    }
    return &D_00794420;
}
