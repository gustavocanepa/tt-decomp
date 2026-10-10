#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002E5C78_arg0 {
    char pad0[0x5B4];
    f32 unk5B4;
};

s32 func_002E5C78(struct func_002E5C78_arg0 *arg0) {
    s32 var_v0;

    var_v0 = 1;
    if (!(arg0->unk5B4 > 0x1.0000000000000p-2f)) {
        var_v0 = 0;
    }
    return var_v0;
}
