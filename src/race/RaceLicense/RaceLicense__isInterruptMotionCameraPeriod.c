#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 LicenseConcourse__isCameraPeriod(s32);                             /* extern */

s32 RaceLicense__isInterruptMotionCameraPeriod(s32 arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = 0;
    if (arg1 == 0) {
        var_v0 = LicenseConcourse__isCameraPeriod(arg0 + 0x3A8C0) != 0;
    }
    return var_v0;
}
