#include "types.h"

extern "C" s32 TireWearParameters__isWearAvailable(void *);
extern "C" s32 TireWearParameters__isHeatAvailable(void *);

extern "C" s32 func_0030FEB8(void *o) {
    s32 r = 0;
    if (TireWearParameters__isWearAvailable(o) || TireWearParameters__isHeatAvailable(o))
        r = 1;
    return r;
}
