#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct mImagePS2__virtual_10_arg0 {
    char pad0[0x14];
    s32 unk14;
};

s32 mImagePS2__virtual_10(struct mImagePS2__virtual_10_arg0 *arg0) {
    return arg0->unk14 != 0;
}
