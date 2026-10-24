#include "types.h"

extern "C" void func_005442B0();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005F0410[];
extern int D_005F0420;

extern int D_00794510;

extern "C" void *func_005463C0(void) {
    if (D_00794510 == 0) {
        func_005442B0();
        func_0050C6C0(&D_00794510, D_005F0410, &D_005F0420, 1);
    }
    return &D_00794510;
}
