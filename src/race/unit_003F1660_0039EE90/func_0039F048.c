#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0039F048_arg0 {
    char pad0[0x12];
    u8 unk12;
};

s32 func_0039F048(struct func_0039F048_arg0 *arg0) {
    s32 var_a0;
    u8 temp_v1;

    temp_v1 = arg0->unk12;
    var_a0 = 0;
    if ((temp_v1 == 1) || (temp_v1 == 7)) {
        var_a0 = 1;
    }
    return var_a0;
}
