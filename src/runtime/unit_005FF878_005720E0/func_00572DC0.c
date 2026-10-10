#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F42C8(s32);                         /* extern */
s32 func_004F4348(s32);                         /* extern */

extern char D_00598334[];
struct func_00572DC0_arg0 {
    char pad0[0x3C];
    s32 unk3C;
};

s32 func_00572DC0(struct func_00572DC0_arg0 *arg0) {
    s32 temp_s1;

    func_004F4348(*(s32 *)(s32)D_00598334);
    temp_s1 = arg0->unk3C;
    func_004F42C8(*(s32 *)(s32)D_00598334);
    return temp_s1;
}
