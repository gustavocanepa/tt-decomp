#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0019B400();                            /* extern */
s32 func_001984E8(void *, s32);             /* extern */

extern char D_005AC458[];
struct func_005202C8_arg0 {
    char pad0[0x4C];
    s32 unk4C;
    s32 unk50;
};

void func_005202C8(struct func_005202C8_arg0 *arg0) {
    func_0019B400();
    arg0->unk50 = 0;
    arg0->unk4C = (s32)D_005AC458;
    func_001984E8(arg0, 0);
}
