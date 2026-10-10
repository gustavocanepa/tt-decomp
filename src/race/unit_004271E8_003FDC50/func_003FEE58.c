#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_003FEB98(s32);                             /* extern */

struct func_003FEE58_arg0 {
    char pad0[0x8];
    s32 unk8;
};

u32 func_003FEE58(struct func_003FEE58_arg0 *arg0) {
    return (u32) ~func_003FEB98(arg0->unk8) >> 0x1F;
}
