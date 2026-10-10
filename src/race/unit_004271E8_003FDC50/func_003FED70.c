#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_003FEB98(s32);                             /* extern */

struct func_003FED70_arg0 {
    char pad0[0x4];
    s32 unk4;
};

u32 func_003FED70(struct func_003FED70_arg0 *arg0) {
    return (u32) ~func_003FEB98(arg0->unk4) >> 0x1F;
}
