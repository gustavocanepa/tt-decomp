#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_0024BAE8(s32);                         /* extern */
void *func_0053B148();                              /* extern */

s32 func_00233A40(s32 arg0) {
    if (M2C_FIELD(func_0053B148(), s32 *, 8) == 0) {
        func_0024BAE8(arg0);
    }
}
