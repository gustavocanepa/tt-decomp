#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00571C78(s32, s32);                    /* extern */

struct func_004AD378_arg0 {
    char pad0[0x44];
    s32 unk44;
    char pad48[0x4];
    s32 unk4C;
};

void func_004AD378(struct func_004AD378_arg0 *arg0) {
    func_00571C78(arg0->unk4C, arg0->unk44);
}
