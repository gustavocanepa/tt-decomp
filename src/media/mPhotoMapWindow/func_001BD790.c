#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void *func_001BD180();                              /* extern */

s32 func_001BD790(s32 arg0) {
    return M2C_FIELD(func_001BD180(), s32 *, 4) + (arg0 * 0x10);
}
