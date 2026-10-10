#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00317DE0(s32);                         /* extern */
s32 func_00321898();                            /* extern */

struct func_003AC118_arg0 {
    char pad0[0x198];
    s32 unk198;
};

void func_003AC118(void *arg0, s32 arg1) {
    func_00321898();
    func_00317DE0(arg0 + 0x180);
    ((struct func_003AC118_arg0 *)arg0)->unk198 = arg1;
}
