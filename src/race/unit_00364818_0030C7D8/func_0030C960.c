#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0030C960_temp_a0 {
    char pad0[0x1694];
    s16 unk1694;
};

s16 func_0030C960(void **arg0) {
    s16 var_v0;
    struct func_0030C960_temp_a0 *temp_a0;

    temp_a0 = *arg0;
    var_v0 = 0;
    if (temp_a0 != NULL) {
        var_v0 = temp_a0->unk1694;
    }
    return var_v0;
}
