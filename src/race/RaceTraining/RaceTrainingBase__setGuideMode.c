#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct RaceMission__virtual_152_arg0 {
    char pad0[0x13C38];
    s32 unk13C38;
    s32 unk13C3C;
};

void RaceTrainingBase__setGuideMode(struct RaceMission__virtual_152_arg0 *arg0, s32 arg1) {
    arg0->unk13C38 = arg1;
    arg0->unk13C3C = 0;
}
