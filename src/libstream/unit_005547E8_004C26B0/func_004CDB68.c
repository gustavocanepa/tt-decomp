#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern s32 D_00598410;

s32 func_004FA6B0(s32, s32);                        /* extern */
s32 func_004FA710();                                /* extern */
s32 func_004FA830(s32);                         /* extern */

struct func_004CDB68_arg0 {
    char pad0[0x1C];
    s32 unk1C;
    char pad20[0x4];
    s32 unk24;
};

void func_004CDB68(struct func_004CDB68_arg0 *arg0) {
    s32 temp_s2;
    s32 temp_v0;
    s32 temp_v0_2;

    temp_v0 = func_004FA710();
    temp_s2 = func_004FA6B0(temp_v0, arg0->unk24);
    temp_v0_2 = arg0->unk1C;
    if (temp_v0_2 != -1) {
        func_004FA830(temp_v0_2);
        arg0->unk1C = -1;
        D_00598410 = 0;
    }
    func_004FA6B0(temp_v0, temp_s2);
}
