#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0019B400();                            /* extern */
s32 func_00198490(void *, s32);             /* extern */

extern char D_005AC570[];
struct func_005201D0_arg0 {
    char pad0[0x4C];
    s32 unk4C;
    s32 unk50;
};

void func_005201D0(struct func_005201D0_arg0 *arg0) {
    func_0019B400();
    arg0->unk50 = 0;
    arg0->unk4C = (s32)D_005AC570;
    func_00198490(arg0, 0);
}
