#include "types.h"
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_002E6568();                                /* extern */

struct func_002E6598_arg0 {
    char pad0[0x574];
    f32 unk574;
};

f32 func_002E6598(void *arg0, f32 fparg0) {
    f32 temp_f20;
    s32 temp_v0;

    temp_v0 = func_002E6568();
    temp_f20 = fparg0 + ((struct func_002E6598_arg0 *)arg0)->unk574;
    return (M2C_FIELD(((temp_v0 * 4) + arg0), f32 *, 0x99C) * temp_f20) + (M2C_FIELD(((temp_v0 * 0x34) + arg0), f32 *, 0x838) * (1.0f - temp_f20));
}
