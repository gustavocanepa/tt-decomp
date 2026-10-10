#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_004A6198(f32);                             /* extern */

f32 func_003CF090(f32 fparg0, f32 fparg1, f32 fparg2) {
    f32 temp_f22;

    temp_f22 = fparg0 - fparg2;
    return (temp_f22 - (fparg1 * func_004A6198(temp_f22 / fparg1))) + fparg2;
}
