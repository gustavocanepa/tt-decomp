#include "types.h"

extern "C" void func_0052FE98();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EA938[];
extern int D_005EA948;

extern int D_00793D50;

extern "C" void *func_0052D3A8(void) {
    if (D_00793D50 == 0) {
        func_0052FE98();
        func_0050C6C0(&D_00793D50, D_005EA938, &D_005EA948, 1);
    }
    return &D_00793D50;
}
