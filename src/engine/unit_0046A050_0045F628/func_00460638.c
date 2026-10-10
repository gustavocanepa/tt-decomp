/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004607D8(void *, s32);                 /* extern */
s32 func_0055B128(s32, s32);                    /* extern */
s32 func_005607F0(s32, s32);                    /* extern */
s32 func_00560FA0(s32);                         /* extern */

struct func_00460638_arg0 {
    char pad0[0x18];
    s32 unk18;
};

void func_00460638(void *arg0, s32 arg1, s32 arg2) {
    func_00560FA0(arg0 + 4);
    func_0055B128(arg0 + 0x10, arg1);
    func_005607F0(arg0 + 0x14, arg1);
    ((struct func_00460638_arg0 *)arg0)->unk18 = 0;
    func_004607D8(arg0, arg2);
}
