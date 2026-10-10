#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_00207150(s32);                         /* extern */
void *func_005366A8();                              /* extern */

s32 func_002226E8(s32 arg0) {
    if (M2C_FIELD(func_005366A8(), s32 *, 8) == 0) {
        func_00207150(arg0);
    }
}
