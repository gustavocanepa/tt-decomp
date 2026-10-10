#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00467728(void *);                      /* extern */
s32 func_0046AC48(s32);                         /* extern */

struct mImagePS2__virtual_12_arg0_unk14 {
    char pad0[0x18];
    s32 unk18;
};
struct mImagePS2__virtual_12_arg0 {
    char pad0[0x14];
    struct mImagePS2__virtual_12_arg0_unk14 *unk14;
};

s32 mImagePS2__virtual_12(struct mImagePS2__virtual_12_arg0 *arg0) {
    void *temp_v0;

    temp_v0 = arg0->unk14;
    if (temp_v0 != NULL) {
        func_00467728(temp_v0);
        func_0046AC48(arg0->unk14->unk18);
    }
}
