#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00456BE8(void *, s32);                     /* extern */
s32 func_0050E1A8(void *);                      /* extern */

extern char D_005D76B0[];
struct func_003ED468_arg0 {
    char pad0[0x8E8];
    s32 unk8E8;
};

void func_003ED468(struct func_003ED468_arg0 *arg0, s32 arg1) {
    arg0->unk8E8 = (s32)D_005D76B0;
    func_00456BE8(arg0, 0);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
