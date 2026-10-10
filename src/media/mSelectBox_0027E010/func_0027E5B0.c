#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_00278A90(s32);                         /* extern */
void *func_00545BE0();                              /* extern */

s32 func_0027E5B0(s32 arg0) {
    if (M2C_FIELD(func_00545BE0(), s32 *, 8) == 0) {
        func_00278A90(arg0);
    }
}
