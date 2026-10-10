#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003E6F48(f32);                             /* extern */

f32 func_003E5C08(f32 *arg0, f32 fparg0) {
    f32 temp_f20;

    temp_f20 = *arg0 - fparg0;
    return (temp_f20 - ((f32) func_003E6F48(temp_f20 / 0x1.921fb40000000p+2f) * 0x1.921fb40000000p+2f)) + fparg0;
}
