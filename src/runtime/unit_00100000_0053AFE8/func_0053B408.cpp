#include "types.h"

extern "C" void func_0052FE98();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005ED440[];
extern int D_005ED450;

extern int D_00794110;

extern "C" void *func_0053B408(void) {
    if (D_00794110 == 0) {
        func_0052FE98();
        func_0050C6C0(&D_00794110, D_005ED440, &D_005ED450, 1);
    }
    return &D_00794110;
}
