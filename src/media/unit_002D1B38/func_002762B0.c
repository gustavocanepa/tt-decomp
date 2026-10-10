#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0020D640(s32);                             /* extern */

struct func_002762B0_arg0 {
    char pad0[0x18];
    f32 unk18;
    char pad1C[0x4];
    s32 unk20;
};

f32 func_002762B0(struct func_002762B0_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk20;
    if ((temp_v0 != 0) && (func_0020D640(temp_v0) != 0)) {
        return arg0->unk18;
    }
    return 0.0f;
}
