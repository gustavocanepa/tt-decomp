#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_003F18A0(s32, s32);                    /* extern */
s32 func_005607F0(s32, s32);                    /* extern */
s32 func_00560AF8(s32);                         /* extern */

struct func_003F1980_arg0 {
    u16 unk0;
    char pad2[0x2];
    s32 unk4;
};

void func_003F1980(void *arg0, s32 arg1) {
    s32 temp_a0;
    s32 var_s1;

    func_00560AF8(arg0 + 4);
    func_005607F0(arg0 + 0x10, arg1);
    var_s1 = 0;
    if (((struct func_003F1980_arg0 *)arg0)->unk0 != 0) {
        do {
            temp_a0 = var_s1 << 5;
            var_s1 += 1;
            func_003F18A0(((struct func_003F1980_arg0 *)arg0)->unk4 + temp_a0, arg1);
        } while (var_s1 < (s32) ((struct func_003F1980_arg0 *)arg0)->unk0);
    }
}
