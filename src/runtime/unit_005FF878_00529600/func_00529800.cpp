#include "types.h"

extern "C" void func_00529600();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005E99F0[];
extern int D_005E9A00;

extern int D_00793C20;

extern "C" void *func_00529800(void) {
    if (D_00793C20 == 0) {
        func_00529600();
        func_0050C6C0(&D_00793C20, D_005E99F0, &D_005E9A00, 1);
    }
    return &D_00793C20;
}
