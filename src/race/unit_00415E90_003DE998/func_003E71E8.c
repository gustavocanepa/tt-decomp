#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_004EE530();                                /* extern */

void func_003E71E8(f32 *arg0, f32 *arg1) {
    f32 temp_f0;

    temp_f0 = func_004EE530();
    *arg0 = temp_f0;
    *arg1 = 1.5707963f - temp_f0;
}
