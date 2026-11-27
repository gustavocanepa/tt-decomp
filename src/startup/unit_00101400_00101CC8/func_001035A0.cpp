#include "types.h"

extern s32 D_00579320;
extern s32 D_0057931C;

extern "C" void func_00102880(s32 arg0);

extern "C" void func_001035A0(void) {
    if (D_00579320 != 0) {
        D_00579320 = 0;
        func_00102880(D_0057931C);
    }
}
