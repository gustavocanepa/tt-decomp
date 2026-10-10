/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0043A180();                            /* extern */
s32 func_0046AB68(s32, s32, s32, s32, s32, s32); /* extern */

struct func_00439B48_arg0 {
    char pad0[0x14];
    s32 unk14;
};

void func_00439B48(struct func_00439B48_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (arg0->unk14 == 0) {
        func_0043A180();
    }
    func_0046AB68(arg1, arg2, arg3, arg4, 0, 0);
}
