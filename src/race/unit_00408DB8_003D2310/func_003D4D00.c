#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003BDB38(s32);                             /* extern */
s32 func_003D4D68(void *);                      /* extern */

struct func_003D4D00_arg0 {
    char pad0[0x130];
    s32 unk130;
};

void func_003D4D00(struct func_003D4D00_arg0 *arg0) {
    if (func_003BDB38(arg0->unk130) == 1) {
        func_003D4D68(arg0);
        return;
    }
    if (func_003BDB38(arg0->unk130) == 4) {
        func_003D4D68(arg0);
    }
}
