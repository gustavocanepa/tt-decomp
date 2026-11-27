#include "types.h"

extern "C" void func_0053C698();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005E9378[];
extern int D_005E9388;

extern int D_00793BD0;

extern "C" void *func_005290F0(void) {
    if (D_00793BD0 == 0) {
        func_0053C698();
        func_0050C6C0(&D_00793BD0, D_005E9378, &D_005E9388, 1);
    }
    return &D_00793BD0;
}
