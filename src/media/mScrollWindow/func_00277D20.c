#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_001B4B10(s32);                         /* extern */
void *func_00544D08();                              /* extern */

s32 func_00277D20(s32 arg0) {
    if (M2C_FIELD(func_00544D08(), s32 *, 8) == 0) {
        func_001B4B10(arg0);
    }
}
