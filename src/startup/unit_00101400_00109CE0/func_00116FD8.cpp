#include "types.h"

extern s32 *D_00579774;
extern s32 D_00579778[];
extern "C" s32 func_004A8268(void *arg0, s32 arg1);

extern "C" void func_00116FD8(void *arg0, void *arg1) {
    s32 *state = D_00579774;
    if (state != 0) {
        s32 index = 0;
        *state = 0;
        for (; index < 0x1A; index++) {
            if (func_004A8268(arg1, D_00579778[index]) == 0) {
                *D_00579774 = index;
                break;
            }
        }
    }
}
