#include "types.h"

extern "C" void func_0052FE98();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005E88D0[];
extern int D_005E88E0;

extern int D_00793AD0;

extern "C" void *func_00524A00(void) {
    if (D_00793AD0 == 0) {
        func_0052FE98();
        func_0050C6C0(&D_00793AD0, D_005E88D0, &D_005E88E0, 1);
    }
    return &D_00793AD0;
}
