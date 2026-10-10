#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004A4930(s32);                         /* extern */
s32 func_004A4970(s32);                         /* extern */

struct func_0011BDE8_arg0 {
    char pad0[0x2AC];
    s32 unk2AC;
    s32 unk2B0;
};

f32 func_0011BDE8(void *arg0) {
    f32 var_f0;
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_s2;

    temp_s1 = arg0 + 0x10;
    func_004A4930(temp_s1);
    temp_s2 = ((struct func_0011BDE8_arg0 *)arg0)->unk2AC;
    temp_s0 = ((struct func_0011BDE8_arg0 *)arg0)->unk2B0;
    func_004A4970(temp_s1);
    var_f0 = 0.0f;
    if (temp_s0 != 0) {
        var_f0 = (f32) temp_s2 / (f32) temp_s0;
    }
    return var_f0;
}
