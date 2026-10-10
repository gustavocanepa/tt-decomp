#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 Pitmen__isHandCameraPeriod(s32);                             /* extern */

s32 func_002CF4B8(s32 arg0) {
    return Pitmen__isHandCameraPeriod(arg0 + 0x36C0) != 0;
}
