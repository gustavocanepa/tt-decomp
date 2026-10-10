#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E6998_arg0_unk10 {
    char pad0[0x26E];
    u16 unk26E;
};
struct func_002E6998_arg0 {
    char pad0[0x10];
    struct func_002E6998_arg0_unk10 *unk10;
    char pad14[0x60A];
    s16 unk61E;
    char pad620[0x25];
    u8 unk645;
};

s32 func_002E6998(struct func_002E6998_arg0 *arg0) {
    s32 var_a2;

    var_a2 = 0;
    if (((s32) arg0->unk10->unk26E < arg0->unk61E) || (arg0->unk645 != 0)) {
        var_a2 = 1;
    }
    return var_a2;
}
