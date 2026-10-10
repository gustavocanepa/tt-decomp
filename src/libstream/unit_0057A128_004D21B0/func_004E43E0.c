#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s8 func_004E25C0(s32);                              /* extern */
s32 func_004E5458(s32, s8);                     /* extern */

struct func_004E43E0_temp_a0 {
    char pad0[0x1A];
    u8 unk1A;
};

s32 func_004E43E0(void **arg0) {
    s32 temp_v0;
    struct func_004E43E0_temp_a0 *temp_a0;

    temp_v0 = func_004E25C0(M2C_FIELD(*arg0, s32 *, 0));
    if (temp_v0 == -1) {
        temp_a0 = *arg0;
        temp_a0->unk1A = (u8) (temp_a0->unk1A | 3);
        return 0;
    }
    func_004E5458(M2C_FIELD(*arg0, s32 *, 0), temp_v0);
    return 1;
}
