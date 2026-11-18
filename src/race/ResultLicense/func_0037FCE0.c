#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

union AliasAny { s8 b; u8 ub; s16 h; u16 uh; s32 w; u32 uw; s64 d; f32 f; };
void func_0037FCE0(void *arg0) {
    void *temp_v0;

    temp_v0 = M2C_FIELD(arg0, void **, 0x870);
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, union AliasAny *, 0xE3B4).w = 0;
        M2C_FIELD(M2C_FIELD(arg0, void **, 0x870), s32 *, 0xE3D0) = 0;
    }
}
