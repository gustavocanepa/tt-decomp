#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 Pitmen__isPitCameraPeriod(s32);                             /* extern */

s32 func_002CF498(s32 arg0) {
    return Pitmen__isPitCameraPeriod(arg0 + 0x36C0) != 0;
}
