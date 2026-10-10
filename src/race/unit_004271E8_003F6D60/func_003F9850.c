#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003F97A8(s32);                             /* extern */
s32 func_00400CF0(s32);                         /* extern */

struct func_003F9850_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x10];
    s32 unk18;
};

void func_003F9850(struct func_003F9850_arg0 *arg0) {
    s32 temp_a0;
    s32 var_s1;
    s32 var_s2;
    s32 var_s3;

    var_s2 = 0;
    var_s3 = 0;
    if (arg0->unk18 > 0) {
        var_s1 = 0;
        do {
            var_s2 += 1;
            temp_a0 = arg0->unk4 + var_s1;
            var_s1 += 0x1F8;
            var_s3 += func_003F97A8(temp_a0);
        } while (var_s2 < arg0->unk18);
    }
    func_00400CF0(var_s3);
}
