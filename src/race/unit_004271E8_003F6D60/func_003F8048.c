#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003FD070(s32, s32);                    /* extern */

struct func_003F8048_arg0 {
    char pad0[0xDC];
    s32 unkDC;
    s32 unkE0;
};

void func_003F8048(struct func_003F8048_arg0 *arg0) {
    func_003FD070(arg0->unkE0, arg0->unkDC);
}
