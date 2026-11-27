#include "types.h"

extern "C" void func_00536BC0();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EDDF0[];
extern int D_005EDE00;

extern int D_007941D0;

extern "C" void *func_0053C698(void) {
    if (D_007941D0 == 0) {
        func_00536BC0();
        func_0050C6C0(&D_007941D0, D_005EDDF0, &D_005EDE00, 1);
    }
    return &D_007941D0;
}
