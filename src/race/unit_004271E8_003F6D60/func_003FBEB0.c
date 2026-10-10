#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003FB338(s32);                         /* extern */

struct func_003FBEB0_arg0 {
    char pad0[0x8210];
    s32 unk8210;
};

void func_003FBEB0(void *arg0, s32 arg1, s32 arg2) {
    func_003FB338(arg0 + (arg1 << 5) + 8);
    if (arg2 != 0) {
        ((struct func_003FBEB0_arg0 *)arg0)->unk8210 = arg1;
    }
}
