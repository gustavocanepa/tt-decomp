#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 HIO__read8(s32);                             /* extern */

struct mSetState__virtual_09_arg0 {
    char pad0[0x8];
    s32 unk8;
};

void mSetState__read(struct mSetState__virtual_09_arg0 *arg0, s32 arg1) {
    arg0->unk8 = HIO__read8(arg1);
}
