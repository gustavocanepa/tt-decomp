#include "types.h"

extern s32 D_00579318;

extern "C" void func_00109650(s32 arg0, s32 arg1);

extern "C" void func_00109980(s32 arg0) {
    s32 temp_v1 = D_00579318;
    if (temp_v1 != 0) {
        func_00109650(temp_v1, arg0);
    }
}
