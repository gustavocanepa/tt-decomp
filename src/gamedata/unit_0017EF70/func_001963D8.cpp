#include "types.h"

extern f32 D_00579EA4;
extern f32 D_00579EA8;

extern "C" void func_001963D8(f32 fparg0) {
    f32 temp_f0 = D_00579EA8;
    D_00579EA8 = fparg0;
    D_00579EA4 = temp_f0;
}
