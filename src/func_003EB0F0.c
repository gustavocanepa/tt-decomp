/* compiler: ee-gcc2.9-991111 */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_003EB0F0(void *arg0) {
    s32 var_a0;
    void *temp_v1;

    temp_v1 = arg0 + 0x150;
    if (M2C_FIELD(arg0, s32 *, 0x1CC) != 0) {
        var_a0 = 0;
        if (M2C_FIELD(temp_v1, s16 *, 8) == 0) {
            var_a0 = M2C_FIELD(temp_v1, s16 *, 0xA) == 0;
        }
        return var_a0;
    }
    return 1;
}
