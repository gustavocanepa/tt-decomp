#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00447EC8(s32, s32);                        /* extern */
s32 func_004A8368(s32);                             /* extern */

struct func_00440900_temp_s1 {
    char pad0[0x4];
    s32 unk4;
};

struct func_00440900_arg0 {
    char pad0[0x1A];
    u8 unk1A;
    char pad1B[0x11];
    s32 unk2C;
};

void func_00440900(void *arg0, s32 arg1) {
    s32 temp_v0;
    s32 temp_v0_2;
    struct func_00440900_temp_s1 *temp_s1;

    temp_s1 = arg0 + 0x2C;
    if ((temp_s1->unk4 != 0) && !(((struct func_00440900_arg0 *)arg0)->unk1A & 0x80)) {
        temp_v0 = func_00447EC8(arg1, ((struct func_00440900_arg0 *)arg0)->unk2C);
        if (temp_v0 != 0) {
            temp_v0_2 = func_004A8368(temp_v0);
            ((struct func_00440900_arg0 *)arg0)->unk2C = temp_v0;
            temp_s1->unk4 = (s32) (temp_v0_2 + 1);
        }
        ((struct func_00440900_arg0 *)arg0)->unk1A = (u8) (((struct func_00440900_arg0 *)arg0)->unk1A | 0x80);
    }
}
