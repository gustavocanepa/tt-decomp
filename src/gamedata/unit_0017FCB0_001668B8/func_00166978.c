/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003FD748(s32, s32, s32);                   /* extern */
s32 func_003FEEC8(s32, s32, s32);               /* extern */

struct func_00166978_arg0 {
    char pad0[0x10];
    s32 unk10;
};

void func_00166978(struct func_00166978_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    func_003FEEC8(func_003FD748(arg0->unk10, arg2, arg4), arg3, arg1);
}
