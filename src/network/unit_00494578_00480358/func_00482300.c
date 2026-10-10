#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00482300_arg0 {
    char pad0[0x85C];
    s32 unk85C;
};
struct func_00482300_temp_a0 {
    char pad0[0x238];
    s32 unk238;
};
struct func_00482300_var_a0 {
    s8 unk0;
    char pad1[0x3];
    s16 unk4;
    s16 unk6;
};

s32 func_00482300(void *arg0, s32 arg1) {
    s32 temp_v0;
    s32 var_a2;
    s32 var_a3;
    void *temp_a0;
    void *var_a0;

    temp_a0 = arg0 + ((1 - ((struct func_00482300_arg0 *)arg0)->unk85C) * 0x41C);
    temp_v0 = ((struct func_00482300_temp_a0 *)temp_a0)->unk238;
    var_a3 = 0;
    if (temp_v0 > 0) {
        var_a0 = temp_a0 + 0x23C;
        var_a2 = temp_v0;
        do {
            var_a2 -= 1;
            if (((struct func_00482300_var_a0 *)var_a0)->unk0 == arg1) {
                var_a3 += ((struct func_00482300_var_a0 *)var_a0)->unk6 - ((struct func_00482300_var_a0 *)var_a0)->unk4;
            }
            var_a0 += 8;
        } while (var_a2 != 0);
    }
    return var_a3;
}
