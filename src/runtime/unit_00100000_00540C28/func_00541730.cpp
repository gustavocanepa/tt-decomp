#include "types.h"

extern "C" void func_00545948();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EEC88[];
extern int D_005EEC98;

extern int D_00794310;

extern "C" void *func_00541730(void) {
    if (D_00794310 == 0) {
        func_00545948();
        func_0050C6C0(&D_00794310, D_005EEC88, &D_005EEC98, 1);
    }
    return &D_00794310;
}
