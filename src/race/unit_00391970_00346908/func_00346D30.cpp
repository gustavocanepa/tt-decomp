#include "types.h"

extern s32 D_00794E70;

extern "C" void RaceCarSound__fadeMasterVolume(f32 fparg0, f32 fparg1);

extern "C" void func_00346D30(f32 fparg0) {
    D_00794E70 = 0;
    RaceCarSound__fadeMasterVolume(1.0f, fparg0);
}
