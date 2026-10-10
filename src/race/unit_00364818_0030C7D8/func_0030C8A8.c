#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0030C8A8_temp_a0 {
    char pad0[0x18];
    s16 unk18;
};

s16 func_0030C8A8(void **arg0) {
    s16 var_v0;
    struct func_0030C8A8_temp_a0 *temp_a0;

    temp_a0 = *arg0;
    var_v0 = 0;
    if (temp_a0 != NULL) {
        var_v0 = temp_a0->unk18;
    }
    return var_v0;
}
