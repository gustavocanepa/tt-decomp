#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_001D8E78(s32);                         /* extern */
void *func_00536130();                              /* extern */

s32 func_002202C8(s32 arg0) {
    if (M2C_FIELD(func_00536130(), s32 *, 8) == 0) {
        func_001D8E78(arg0);
    }
}
