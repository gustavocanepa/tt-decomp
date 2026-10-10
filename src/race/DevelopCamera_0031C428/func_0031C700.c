#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0031C700_temp_a0_2 {
    char pad0[0x140];
    s32 unk140;
    char pad144[0x8];
    s32 unk14C;
};

struct func_0031C700_temp_a0 {
    char pad0[0x15C];
    s32 unk15C;
};

s32 func_0031C700(s32 arg0, s32 arg1) {
    s32 var_v0;
    void *temp_a0;
    struct func_0031C700_temp_a0_2 *temp_a0_2;

    temp_a0 = (arg1 * 0x1B4) + arg0;
    temp_a0_2 = temp_a0 + 0x10;
    var_v0 = temp_a0_2->unk140;
    if ((((struct func_0031C700_temp_a0 *)temp_a0)->unk15C ^ 9) != 0) {
        var_v0 = temp_a0_2->unk14C;
    }
    return var_v0;
}
