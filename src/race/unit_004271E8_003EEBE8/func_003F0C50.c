#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_003F1200(s32);                             /* extern */

struct func_003F0C50_arg0 {
    char pad0[0x4];
    s32 unk4;
};

s32 func_003F0C50(struct func_003F0C50_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk4;
    if (temp_v0 != 0) {
        return func_003F1200(temp_v0);
    }
    return 0;
}
