#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004B2AC8();                                /* extern */
f32 func_004B2B90(s32);                             /* extern */

f32 func_004B2B08(f32 fparg0) {
    return func_004B2B90(func_004B2AC8()) * fparg0;
}
