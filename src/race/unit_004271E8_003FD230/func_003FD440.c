#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00410D60(s8 *);                            /* extern */

struct func_003FD440_arg0 {
    char pad0[0x1164];
    s32 unk1164;
};

void func_003FD440(struct func_003FD440_arg0 *arg0, s8 *arg1) {
    if (*arg1 == 0) {
        arg0->unk1164 = 0;
        return;
    }
    arg0->unk1164 = func_00410D60(arg1);
}
