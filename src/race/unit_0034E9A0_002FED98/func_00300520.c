#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void *func_002F04D8();                              /* extern */
s32 func_00305370(s32, s32, s32);           /* extern */

void func_00300520(s32 *arg0, s32 arg1) {
    if ((u32) (M2C_FIELD(func_002F04D8(), s8 *, 0x58A) - 1) >= 2U) {
        func_00305370(*arg0, arg1, 6);
    }
}
