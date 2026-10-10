/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00382A88(s32, s32);                    /* extern */

void CameraSys__CameraManager__initWindowInput(s32 arg0, s32 arg1, s32 arg2) {
    func_00382A88((arg1 * 0x2750) + arg0 + 0x2750, arg2);
}
