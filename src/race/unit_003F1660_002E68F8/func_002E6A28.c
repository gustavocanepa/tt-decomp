#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E6A28_arg0 {
    char pad0[0x58B];
    u8 unk58B;
    char pad58C[0x44];
    s16 unk5D0;
};

s32 func_002E6A28(struct func_002E6A28_arg0 *arg0) {
    s32 var_v1;

    var_v1 = 0;
    if (arg0->unk5D0 == 0) {
        var_v1 = arg0->unk58B == 1;
    }
    return var_v1;
}
