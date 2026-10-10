#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void *func_002FD378(s32);                           /* extern */

/* A member array indexed by a variable: base + index (a struct field), not index + base. */
#define M2C_ARRAY(base, T, off, idx) (((struct { char pad[off]; T a[1]; } *)(base))->a[idx])
struct func_0030C390_temp_v0_2 {
    char pad0[0x1];
    u8 unk1;
};
struct func_0030C390_temp_v1 {
    char pad0[0x4];
    f32 unk4;
    char pad8[0x8];
    f32 unk10;
};

f32 func_0030C390(s32 *arg0, s32 arg1) {
    f32 var_f0;
    s32 temp_v0;
    u8 var_a1;
    struct func_0030C390_temp_v0_2 *temp_v0_2;
    struct func_0030C390_temp_v1 *temp_v1;

    var_f0 = 0x0.0p+0f;
    temp_v0 = *arg0;
    if (temp_v0 != 0) {
        temp_v0_2 = func_002FD378(temp_v0 + 0x600);
        var_a1 = 0;
        if (arg1 < (s32) temp_v0_2->unk1) {
            var_a1 = M2C_ARRAY(temp_v0_2, u8, 0x14, arg1);
        }
        temp_v1 = *arg0 + (var_a1 * 0x74) + 0x914;
        var_f0 = temp_v1->unk4 - temp_v1->unk10;
    }
    return var_f0;
}
