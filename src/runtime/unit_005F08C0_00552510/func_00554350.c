#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00554350_arg0 {
    char pad0[0xD8C];
    s32 unkD8C;
};

s32 func_00554350(struct func_00554350_arg0 *arg0) {
    s32 temp_v1;
    s32 var_a0;

    temp_v1 = arg0->unkD8C;
    var_a0 = 0;
    if ((temp_v1 == 1) || (temp_v1 == 3)) {
        var_a0 = 1;
    }
    return var_a0;
}
