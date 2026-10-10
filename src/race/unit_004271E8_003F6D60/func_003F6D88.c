#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004AF530(s32, s32, s32);       /* extern */

struct func_003F6D88_arg0 {
    char pad0[0x4];
    s32 unk4;
};

s32 func_003F6D88(struct func_003F6D88_arg0 *arg0) {
    return arg0->unk4 - func_004AF530(0x7D5, 4, 2);
}
