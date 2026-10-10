#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00553620_arg0 {
    char pad0[0x295];
    u8 unk295;
    char pad296[0x1];
    u8 unk297;
};

s32 func_00553620(struct func_00553620_arg0 *arg0) {
    s32 var_v1;

    var_v1 = 0;
    if ((arg0->unk297 != 0) || (arg0->unk295 != 0)) {
        var_v1 = 1;
    }
    return var_v1;
}
