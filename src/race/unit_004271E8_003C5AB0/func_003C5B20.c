#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

struct func_003C5B20_var_a0 {
    s32 unk0;
};

s32 func_003C5B20(s32 arg0) {
    s32 var_a1;
    s32 var_v1;
    void *var_a0;

    var_a0 = arg0 + 0x130;
    var_a1 = 0;
    var_v1 = 7;
    do {
        if ((M2C_FIELD(var_a0, s32 *, -0x20) != 0) || (((struct func_003C5B20_var_a0 *)var_a0)->unk0 != 0)) {
            var_a1 += 1;
        }
        var_v1 -= 1;
        var_a0 += 4;
    } while (var_v1 >= 0);
    return var_a1;
}
