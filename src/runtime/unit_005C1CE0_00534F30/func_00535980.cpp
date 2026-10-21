#include "types.h"

extern "C" void func_0052FE98();
extern "C" void func_0050C6C0(void *a0, void *a1, void *a2, s32 a3);

extern char D_005EC360[];
extern int D_005EC370;

extern int D_00793F10;

extern "C" void *func_00535980(void) {
    if (D_00793F10 == 0) {
        func_0052FE98();
        func_0050C6C0(&D_00793F10, D_005EC360, &D_005EC370, 1);
    }
    return &D_00793F10;
}
