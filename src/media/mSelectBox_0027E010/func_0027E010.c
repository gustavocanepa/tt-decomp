#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00210118(s32);                             /* extern */
s32 func_0020D888();                                /* extern */
s32 func_0027E1C8(s32, s32);                    /* extern */

s32 func_0027E010(s32 arg0) {
    if (func_0020D888() != 0) {
        func_0027E1C8(arg0, func_00210118(arg0));
    }
}
