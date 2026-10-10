#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003F72C0_arg0 {
    char pad0[0x18];
    s32 unk18;
};

void func_003F72C0(void *arg0, s32 *arg1, s32 arg2) {
    s32 *var_a1;
    s32 *var_a3;
    s32 temp_v1;
    s32 var_a4;

    var_a1 = arg1;
    var_a4 = 0;
    if (arg2 > 0) {
        var_a3 = arg0 + 0x1C;
        do {
            temp_v1 = *var_a1;
            var_a1 += 1;
            var_a4 += 1;
            *var_a3 = temp_v1;
            var_a3 += 1;
        } while (var_a4 < arg2);
    }
    ((struct func_003F72C0_arg0 *)arg0)->unk18 = arg2;
}
