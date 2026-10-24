#include "types.h"

extern "C" void func_0052FE98();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005E6160[];
extern int D_005E6170;

extern int D_007937C0;

extern "C" void *func_0051EAE8(void) {
    if (D_007937C0 == 0) {
        func_0052FE98();
        func_0050C6C0(&D_007937C0, D_005E6160, &D_005E6170, 1);
    }
    return &D_007937C0;
}
