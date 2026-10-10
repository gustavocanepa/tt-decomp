#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_003E6F48(f32);                             /* extern */

void func_003E6E68(f32 *arg0, f32 *arg1, f32 fparg0, f32 fparg1) {
    f32 temp_f0;

    temp_f0 = (f32) func_003E6F48(fparg0 / fparg1);
    *arg0 = temp_f0;
    *arg1 = fparg0 - (temp_f0 * fparg1);
}
