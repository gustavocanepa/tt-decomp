#include "types.h"

extern "C" s32 func_00346710(void *a0);

extern char D_00767CF8[];

extern s32 D_00583F30;

extern "C" void *func_00346770(void) {
    if (D_00583F30 == 0) {
        s32 t = func_00346710(D_00767CF8);
        D_00583F30 = 1;
        (void)t;
    }
    return D_00767CF8;
}
