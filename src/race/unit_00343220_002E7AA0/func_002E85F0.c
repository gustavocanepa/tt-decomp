#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0050F4E8(s32, s32);                    /* extern */

struct func_002E85F0_arg0 {
    char pad0[0x48];
    void *unk48;
};
struct func_002E85F0_temp_a0 {
    char pad0[0x4];
    s32 unk4;
};

s32 func_002E85F0(struct func_002E85F0_arg0 *arg0) {
    struct func_002E85F0_temp_a0 *temp_a0;

    if ((arg0 == NULL) || ((temp_a0 = arg0->unk48) == NULL)) {
        return 0;
    }
    return func_0050F4E8(temp_a0->unk4, 4);
}
