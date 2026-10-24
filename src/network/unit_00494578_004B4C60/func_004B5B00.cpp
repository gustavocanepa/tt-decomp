#include "types.h"

extern "C" void func_004B5570(void);
extern s32 D_00598330;

extern "C" void func_004B5B00(void) {
    if (D_00598330 != 0) {
        D_00598330 = 0;
        func_004B5570();
    }
}
