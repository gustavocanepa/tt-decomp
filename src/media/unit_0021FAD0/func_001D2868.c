#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_001FC930(s32);                         /* extern */
void *func_00529210();                              /* extern */

s32 func_001D2868(s32 arg0) {
    if (M2C_FIELD(func_00529210(), s32 *, 8) == 0) {
        func_001FC930(arg0);
    }
}
