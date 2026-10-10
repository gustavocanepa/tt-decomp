/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00205E78(s32, s32, void *, void *, s32); /* extern */

struct func_00263B28_arg0 {
    char pad0[0x4C];
    s32 unk4C;
};

void func_00263B28(void *arg0, s32 arg1) {
    ((struct func_00263B28_arg0 *)arg0)->unk4C = arg1;
    func_00205E78(arg1, arg0 + 0x50, arg0 + 0x54, arg0 + 0x58, arg0 + 0x5C);
}
