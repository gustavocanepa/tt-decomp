#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void func_002C3DD8(s32, M2C_UNK, M2C_UNK);       /* extern */
void func_002C3F00(s32, M2C_UNK, M2C_UNK);       /* extern */
void func_002C47A8(s32, s32);                    /* extern */

s32 func_002CCF78(void *arg0) {
    s32 temp_s1;

    temp_s1 = arg0 + 0xCC;
    if (M2C_FIELD(arg0, s32 *, 0x234) == 0) {
        func_002C47A8(temp_s1, (s32) ((0x1.5555540000000p+0f / M2C_FIELD(arg0, f32 *, 0x14)) * 0x1.0000000000000p+6f));
        M2C_FIELD(arg0, s32 *, 0x234) = 1;
    }
    if (M2C_FIELD(arg0, s32 *, 0x18) != 0) {
        if (M2C_FIELD(arg0, s32 *, 0x230) == 0) {
            func_002C3F00(temp_s1, 0, 0);
            func_002C3DD8(temp_s1, 0, 0);
            M2C_FIELD(arg0, s32 *, 0x230) = 1;
        }
    }
    return temp_s1;
}
