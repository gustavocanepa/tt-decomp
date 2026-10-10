#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_002E3E50(void **arg0) {
    s32 temp_v1;
    s32 var_a1;

    temp_v1 = M2C_FIELD(M2C_FIELD(*arg0, void **, 0x84), s32 *, 0xD8C);
    var_a1 = 0;
    if ((temp_v1 == 1) || (temp_v1 == 3)) {
        var_a1 = 1;
    }
    return var_a1;
}
