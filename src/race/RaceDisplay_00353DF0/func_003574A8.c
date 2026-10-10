#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003574A8_arg0 {
    char pad0[0x1C];
    s32 unk1C;
    char pad20[0x19];
    u8 unk39;
};

s32 func_003574A8(struct func_003574A8_arg0 *arg0) {
    s32 var_a1;

    var_a1 = 0;
    if ((arg0->unk1C == 2) || (arg0->unk39 != 0)) {
        var_a1 = 1;
    }
    return var_a1;
}
