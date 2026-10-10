#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0042DC88(void);
f32 SystemSoundGetOutputModeVolume(s32, s32);
extern f32 D_00583FC0;
extern f32 D_00583FC4;
extern f32 D_00794E70;
f32 RaceCarSound__getMasterVolume(void) {
    f32 r = SystemSoundGetOutputModeVolume(func_0042DC88(), 2);
    return D_00583FC0 * D_00583FC4 * D_00794E70 * r;
}
