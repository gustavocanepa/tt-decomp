#include "types.h"

extern "C" void func_00545948();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005F01C8[];
extern int D_005F01D8;

extern int D_007944E0;

extern "C" void *func_00545C90(void) {
    if (D_007944E0 == 0) {
        func_00545948();
        func_0050C6C0(&D_007944E0, D_005F01C8, &D_005F01D8, 1);
    }
    return &D_007944E0;
}
