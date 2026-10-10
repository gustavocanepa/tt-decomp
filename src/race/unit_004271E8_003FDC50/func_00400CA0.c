#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A9888();                                /* extern */

s32 func_00400CA0(s32 arg0, s32 arg1, s32 arg2) {
    return func_004A9888() == arg2;
}
