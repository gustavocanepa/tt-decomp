#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00426748_arg0 {
    char pad0[0x38C];
    f32 unk38C;
    char pad390[0x11C];
    s32 unk4AC;
};

void func_00426748(void *arg0, s32 arg1, s32 arg2) {
    f32 *var_a1;
    f32 *var_v0;
    f32 *var_v1;
    f32 temp_f0;
    f32 temp_f1;
    s32 var_a2;

    var_a2 = arg2;
    ((struct func_00426748_arg0 *)arg0)->unk4AC = arg1;
    if (var_a2 > 0) {
        var_a1 = arg1 + 0x38C;
        var_v1 = arg0 + 0x4C8;
        var_v0 = arg0 + 0x4B0;
        do {
            temp_f0 = *var_a1;
            var_a1 += 0x13D;
            var_a2 -= 1;
            temp_f1 = ((struct func_00426748_arg0 *)arg0)->unk38C + temp_f0;
            *var_v0 = temp_f1;
            var_v0 += 1;
            *var_v1 = temp_f1 * temp_f1;
            var_v1 += 1;
        } while (var_a2 != 0);
    }
}
