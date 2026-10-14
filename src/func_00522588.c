#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 *func_001AF2E0(s32, s32);                   /* extern */

f32 func_00522588(s32 arg0) {
    return M2C_FIELD(*func_001AF2E0(arg0, 1), f32 *, 0x2C);
}
