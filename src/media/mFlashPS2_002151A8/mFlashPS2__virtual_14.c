#include "types.h"
void *memcpy(void *, const void *, unsigned int);

f32 func_0043AF80(s32);                             /* extern */

struct mFlashPS2__virtual_14_arg0 {
    char pad0[0xC];
    s32 unkC;
    char pad10[0xC];
    s32 unk1C;
};

f32 mFlashPS2__virtual_14(struct mFlashPS2__virtual_14_arg0 *arg0) {
    s32 temp_v0;

    if (arg0->unk1C == 0) {
        temp_v0 = arg0->unkC;
        if (temp_v0 != 0) {
            return func_0043AF80(temp_v0);
        }
    }
    return 1.0f;
}
