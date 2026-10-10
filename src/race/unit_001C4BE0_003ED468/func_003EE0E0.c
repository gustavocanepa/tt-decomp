#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003EE0E0_arg0 {
    char pad0[0x8E4];
    s32 unk8E4;
    char pad8E8[0x18];
    s32 unk900;
};

s32 func_003EE0E0(struct func_003EE0E0_arg0 *arg0) {
    s32 temp_v1;
    s32 var_v0;

    temp_v1 = arg0->unk900;
    var_v0 = 0;
    if (temp_v1 >= 0) {
        var_v0 = arg0->unk8E4 + temp_v1;
    }
    return var_v0;
}
