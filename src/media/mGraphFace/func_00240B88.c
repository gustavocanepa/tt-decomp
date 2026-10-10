#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_00244630(s32);                         /* extern */
void *func_0053BED0();                              /* extern */

s32 func_00240B88(s32 arg0) {
    if (M2C_FIELD(func_0053BED0(), s32 *, 8) == 0) {
        func_00244630(arg0);
    }
}
