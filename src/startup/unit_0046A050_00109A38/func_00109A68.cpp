#include "types.h"

extern s32 D_00579318;

extern "C" void func_001097F0(s32 arg0);

extern "C" void func_00109A68(void) {
    s32 temp_v1 = D_00579318;
    if (temp_v1 != 0) {
        func_001097F0(temp_v1);
    }
}
