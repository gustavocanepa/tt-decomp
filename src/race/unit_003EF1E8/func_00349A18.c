#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00349A18_arg0 {
    char pad0[0x318];
    s32 unk318;
};

s32 func_00349A18(void *arg0) {
    s32 *var_a0;
    s32 temp_v0;
    s32 var_a1;
    s32 var_v1;

    var_a0 = arg0 + 0x4B8;
    var_a1 = 0;
    var_v1 = 4;
    do {
        temp_v0 = *var_a0;
        var_a0 += 0x68;
        var_v1 -= 1;
        var_a1 += ((struct func_00349A18_arg0 *)arg0)->unk318 < temp_v0;
    } while (var_v1 >= 0);
    return var_a1;
}
