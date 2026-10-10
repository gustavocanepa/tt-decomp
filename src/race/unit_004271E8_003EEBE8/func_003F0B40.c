#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003F0A10(void *, s16, s16, s16, s32, f32, f32); /* extern */
s32 func_003F1860();                                /* extern */

struct func_003F0B40_arg0_unk4 {
    char pad0[0x1C];
    s32 unk1C;
};
struct func_003F0B40_arg0 {
    char pad0[0x4];
    struct func_003F0B40_arg0_unk4 *unk4;
};
struct func_003F0B40_temp_v0 {
    char pad0[0x4];
    s16 unk4;
    s16 unk6;
    s16 unk8;
};

s32 func_003F0B40(struct func_003F0B40_arg0 *arg0, s32 arg1, s32 arg2, f32 fparg0, f32 fparg1) {
    struct func_003F0B40_temp_v0 *temp_v0;

    if (func_003F1860() != 1) {
        return 0;
    }
    temp_v0 = (arg1 * 0x10) + arg0->unk4->unk1C;
    return func_003F0A10(arg0, temp_v0->unk4, temp_v0->unk6, temp_v0->unk8, arg2, fparg0, fparg1);
}
