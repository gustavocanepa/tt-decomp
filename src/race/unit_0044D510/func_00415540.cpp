#include "types.h"

extern "C" void func_0045F6D0(s32 arg0);

extern s32 D_00586EF4;

extern "C" void func_00415540(s32 *arg0) {
    if (*arg0 == 0) {
        *arg0 = 1;
        func_0045F6D0(D_00586EF4);
    }
}
