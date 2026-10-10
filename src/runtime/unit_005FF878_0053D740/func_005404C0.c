#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0050C680(s32, s32);                        /* extern */
s32 func_0050DC80();                                /* extern */

s32 func_005404C0(s32 arg0, s32 arg1) {
    return func_0050C680(arg1, func_0050DC80()) != 0;
}
