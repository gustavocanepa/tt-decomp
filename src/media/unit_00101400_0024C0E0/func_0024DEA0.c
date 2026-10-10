#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_001FC930(s32);                         /* extern */
void *func_005409A8();                              /* extern */

s32 func_0024DEA0(s32 arg0) {
    if (M2C_FIELD(func_005409A8(), s32 *, 8) == 0) {
        func_001FC930(arg0);
    }
}
