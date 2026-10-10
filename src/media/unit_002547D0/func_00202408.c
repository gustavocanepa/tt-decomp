#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002A75A8(s32, s32);                /* extern */
s32 func_002BDA70(s32, s32, s32);       /* extern */

s32 func_00202408(s32 arg0) {
    if (arg0 != 0) {
        func_002A75A8(arg0 + 0x24, 2);
        func_002BDA70(arg0, 0x2C, 4);
    }
}
