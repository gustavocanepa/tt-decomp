#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

u8 *func_002FD3A0(s32);                             /* extern */

struct func_00369B98_arg0 {
    char pad0[0x18];
    s32 unk18;
};

s32 func_00369B98(struct func_00369B98_arg0 *arg0) {
    return *func_002FD3A0(arg0->unk18) == 1;
}
