#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00266228();                            /* extern */
s32 func_0042BA40(s32);                             /* extern */

struct func_002661E8_arg0 {
    char pad0[0x10];
    s32 unk10;
};

void func_002661E8(struct func_002661E8_arg0 *arg0, s32 arg1) {
    func_00266228();
    arg0->unk10 = func_0042BA40(arg1);
}
