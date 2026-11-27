#include "types.h"

extern "C" void func_00522F68();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005E4E08[];
extern int D_005E4E20;

extern int D_00793720;

extern "C" void *func_0051CE70(void) {
    if (D_00793720 == 0) {
        func_00522F68();
        func_0050C6C0(&D_00793720, D_005E4E08, &D_005E4E20, 1);
    }
    return &D_00793720;
}
