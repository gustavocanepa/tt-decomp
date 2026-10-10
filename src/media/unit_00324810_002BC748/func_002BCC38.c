#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002BCC38_arg0 {
    char pad0[0x1C];
    u32 unk1C;
    char pad20[0x4];
    u32 unk24;
};

u32 func_002BCC38(struct func_002BCC38_arg0 *arg0) {
    u32 temp_v1;
    u32 temp_v1_2;
    u32 var_a1;

    temp_v1 = arg0->unk24;
    var_a1 = temp_v1 + (temp_v1 / 10U);
    if (var_a1 != 0) {
        temp_v1_2 = arg0->unk1C;
        var_a1 = (var_a1 < temp_v1_2) ? temp_v1_2 : var_a1;
    }
    return var_a1;
}
