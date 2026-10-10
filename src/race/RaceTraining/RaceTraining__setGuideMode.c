#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RaceTrainingBase__setGuideMode();                            /* extern */

struct RaceTraining__virtual_152_arg0 {
    char pad0[0x14E28];
    s32 unk14E28;
};

void RaceTraining__setGuideMode(struct RaceTraining__virtual_152_arg0 *arg0, s32 arg1) {
    RaceTrainingBase__setGuideMode();
    arg0->unk14E28 = arg1;
}
