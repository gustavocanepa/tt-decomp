#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

union AliasAny { s8 b; u8 ub; s16 h; u16 uh; s32 w; u32 uw; s64 d; f32 f; };
void EngineSound__AttachCallback(void *arg0) {
    s32 frag0;
    s32 frag1;
    void *temp_a0;
    void *temp_a0_2;

    temp_a0 = M2C_FIELD(arg0, void **, 0x20);
    if (temp_a0 != NULL) {
        frag1 = M2C_FIELD(arg0, s32 *, 0x14);
        frag0 = M2C_FIELD(arg0, s32 *, 0x10);
        M2C_FIELD(temp_a0, union AliasAny *, 0x10).w = (s32) (frag0 + frag1);
        temp_a0_2 = M2C_FIELD(arg0, void **, 0x20);
        M2C_FIELD(temp_a0_2, s32 *, 0x18) = (s32) (M2C_FIELD(temp_a0_2, s32 *, 0x18) - M2C_FIELD(arg0, s32 *, 0x14));
    }
}
