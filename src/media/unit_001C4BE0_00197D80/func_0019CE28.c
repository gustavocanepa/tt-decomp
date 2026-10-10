#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0019B400();                            /* extern */
s32 func_0019CE60(void *, s32);             /* extern */

extern char D_005ACFB0[];
struct func_0019CE28_arg0 {
    char pad0[0x4C];
    s32 unk4C;
};

void func_0019CE28(struct func_0019CE28_arg0 *arg0) {
    func_0019B400();
    arg0->unk4C = (s32)D_005ACFB0;
    func_0019CE60(arg0, 0);
}
