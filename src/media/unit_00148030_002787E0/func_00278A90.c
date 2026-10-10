#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_001B9860(s32);                         /* extern */
void *func_00545898();                              /* extern */

s32 func_00278A90(s32 arg0) {
    if (M2C_FIELD(func_00545898(), s32 *, 8) == 0) {
        func_001B9860(arg0);
    }
}
