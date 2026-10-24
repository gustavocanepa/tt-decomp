#include "types.h"

extern "C" void func_0052FE98();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005E6420[];
extern int D_005E6430;

extern int D_007937F0;

extern "C" void *func_0051FC20(void) {
    if (D_007937F0 == 0) {
        func_0052FE98();
        func_0050C6C0(&D_007937F0, D_005E6420, &D_005E6430, 1);
    }
    return &D_007937F0;
}
