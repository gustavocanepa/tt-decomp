static inline float absf(float x) { float r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(x)); return r; }
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern "C" f32 func_004A5A68(f32);                             /* extern */
extern "C" f32 func_004A5C50(f32);                             /* extern */

extern "C" f32 func_0034F308(void *arg0, void *arg1) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f21;
    f32 temp_f22;
    f32 var_f0;
    f32 var_f20;
    s32 temp_v1;

    temp_f21 = M2C_FIELD(arg1, f32 *, 8);
    temp_f22 = absf(temp_f21);
    temp_f0 = absf(func_004A5A68((temp_f22 + M2C_FIELD(arg0, f32 *, 0x14)) / absf(M2C_FIELD(arg1, f32 *, 0))) - 0x1.921fb40000000p+0f);
    var_f20 = M2C_FIELD(arg0, f32 *, 0x10);
    if (M2C_FIELD(arg0, f32 *, 8) < temp_f0) {
        var_f20 = 0x0.0p+0f;
    } else {
        temp_f1 = M2C_FIELD(arg0, f32 *, 4);
        if (temp_f1 < temp_f0) {
            var_f20 *= func_004A5C50((0x1.921fb40000000p+0f / M2C_FIELD(arg0, f32 *, 0xC)) * (temp_f0 - temp_f1));
        }
    }
    temp_v1 = M2C_FIELD(arg0, s32 *, 0);
    if (temp_v1 == 1) {
        if (!(temp_f21 > 0x0.0p+0f)) {
            goto block_7;
        }
        goto block_9;
    }
block_7:
    if ((temp_v1 == 2) && (temp_f21 < 0x0.0p+0f)) {
block_9:
        var_f0 = func_004A5C50((0x1.921fb40000000p+0f / M2C_FIELD(arg0, f32 *, 0x18)) * temp_f22);
        if (var_f0 < 0x0.0p+0f) {
            var_f0 = 0x0.0p+0f;
        }
        var_f20 *= var_f0;
    }
    return absf(var_f20);
}
