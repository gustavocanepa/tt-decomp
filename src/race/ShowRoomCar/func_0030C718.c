#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void *func_002FD378(s32);                           /* extern */

/* A member array indexed by a variable: base + index (a struct field), not index + base. */
#define M2C_ARRAY(base, T, off, idx) (((struct { char pad[off]; T a[1]; } *)(base))->a[idx])
struct func_0030C718_temp_v0 {
    char pad0[0x1];
    u8 unk1;
};

f32 func_0030C718(s32 *arg0, s32 arg1) {
    f32 var_f0;
    s32 temp_s0;
    u8 var_a0;
    struct func_0030C718_temp_v0 *temp_v0;

    var_f0 = 0x0.0p+0f;
    temp_s0 = *arg0;
    if (temp_s0 != 0) {
        temp_v0 = func_002FD378(temp_s0 + 0x600);
        var_a0 = 0;
        if (arg1 < (s32) temp_v0->unk1) {
            var_a0 = M2C_ARRAY(temp_v0, u8, 0x14, arg1);
        }
        var_f0 = M2C_FIELD(((var_a0 * 4) + temp_s0), f32 *, 0x8E8);
    }
    return var_f0;
}
