#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RaceSplitBattleBase__getCameraInput(s32 arg0, s32 arg1) {
    return arg0 + (arg1 * 0x1E0) + 0x32710;
}
