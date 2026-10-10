#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_00338D18_var_a0 {
    s32 unk0;
};

void func_00338D18(s32 arg0) {
    s32 var_v0;
    void *var_a0;

    var_a0 = arg0 + 0x1E4;
    var_v0 = 0xB;
    do {
        var_v0 -= 1;
        M2C_FIELD(var_a0, s32 *, -0x30) = 0;
        ((struct func_00338D18_var_a0 *)var_a0)->unk0 = 0;
        var_a0 += 4;
    } while (var_v0 >= 0);
}
