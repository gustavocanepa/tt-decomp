#include "types.h"

extern "C" void func_0052FE98();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005E5168[];
extern int D_005E5180;

extern int D_00793730;

extern "C" void *func_0051D680(void) {
    if (D_00793730 == 0) {
        func_0052FE98();
        func_0050C6C0(&D_00793730, D_005E5168, &D_005E5180, 1);
    }
    return &D_00793730;
}
