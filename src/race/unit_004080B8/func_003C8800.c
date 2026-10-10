#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_003C8650();                                /* extern */
s32 func_003F0EB0(s32, s32);                        /* extern */

struct func_003C8800_arg0_unk4 {
    char pad0[0x4];
    s32 unk4;
};
struct func_003C8800_arg0 {
    char pad0[0x4];
    struct func_003C8800_arg0_unk4 *unk4;
    char pad8[0x4];
    s32 unkC;
};

void func_003C8800(struct func_003C8800_arg0 *arg0, s32 arg1, s32 arg2) {
    s32 temp_v0;
    s32 temp_v1;

    if (func_003C8650() != 0) {
        temp_v0 = func_003F0EB0(arg0->unk4->unk4, arg2);
        temp_v1 = arg1 * 0x178;
        *(s32 *)(arg0->unkC + temp_v1) = (temp_v0 < 0) ? 0 : temp_v0;
        M2C_FIELD((arg0->unkC + temp_v1), s32 *, 8) = 0;
    }
}
