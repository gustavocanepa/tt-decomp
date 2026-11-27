#include "types.h"

extern "C" void func_005761C0();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_006150D0[];
extern int D_006150E0;

extern int D_007A6440;

extern "C" void *func_005755E8(void) {
    if (D_007A6440 == 0) {
        func_005761C0();
        func_0050C6C0(&D_007A6440, D_006150D0, &D_006150E0, 1);
    }
    return &D_007A6440;
}
