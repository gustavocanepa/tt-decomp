#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002FED98(s32, s32);                    /* extern */

struct func_003A7A18_arg0 {
    char pad0[0x8];
    s32 unk8;
    char padC[0x4];
    void *unk10;
};
struct func_003A7A18_temp_a0 {
    char pad0[0x18];
    s32 unk18;
};

s32 func_003A7A18(struct func_003A7A18_arg0 *arg0) {
    s32 var_a1;
    struct func_003A7A18_temp_a0 *temp_a0;

    var_a1 = -1;
    if (arg0->unk8 == 1) {
        temp_a0 = arg0->unk10;
        if (temp_a0 != NULL) {
            var_a1 = func_002FED98(temp_a0->unk18, -1);
        }
    }
    return var_a1;
}
