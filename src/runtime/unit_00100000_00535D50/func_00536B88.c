#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0050C680(s32, s32);                        /* extern */
s32 func_00536FE0();                                /* extern */

s32 func_00536B88(s32 arg0, s32 arg1) {
    return func_0050C680(arg1, func_00536FE0()) != 0;
}
