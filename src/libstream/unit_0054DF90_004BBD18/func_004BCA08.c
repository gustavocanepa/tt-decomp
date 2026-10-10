#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004BC8B8(s32, s32, s32, s32, s32);         /* extern */
s32 func_004A8268(s32, s32);                        /* extern */

s32 func_004BCA08(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (func_004A8268(arg1, arg0 + 0x240) == 0) {
        return 1;
    }
    return func_004BC8B8(arg0, arg1, arg2, arg3, arg4);
}
