#include "types.h"

extern u8 D_00587140;
extern s32 D_0076E720;
extern s32 D_0076E724;
extern s32 D_0076E728;
extern s32 D_0076E72C;

extern "C" void func_00469BB0(void) {
    if (D_00587140 == 0) {
        D_00587140 = 1;
        D_0076E720 = 0;
        D_0076E724 = 0;
        D_0076E728 = 0;
        D_0076E72C = 0;
    }
}
