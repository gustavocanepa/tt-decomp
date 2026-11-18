#include "types.h"

extern "C" void func_0053C698();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EDAE0[];
extern int D_005EDAF0;

extern int D_007941A0;

extern "C" void *func_0053C358(void) {
    if (D_007941A0 == 0) {
        func_0053C698();
        func_0050C6C0(&D_007941A0, D_005EDAE0, &D_005EDAF0, 1);
    }
    return &D_007941A0;
}
