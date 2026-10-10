/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0043A180();                            /* extern */
s32 func_00470400(s32, s32, s32, s32);          /* extern */

struct func_0043A080_arg0 {
    char pad0[0x10];
    s32 unk10;
    s32 unk14;
};

void func_0043A080(struct func_0043A080_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0->unk14 == 0) {
        func_0043A180();
    }
    func_00470400(arg1, arg2, arg3, arg0->unk10);
}
