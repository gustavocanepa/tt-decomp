#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00104B10(s8 *);                        /* extern */

struct func_0043A5C8_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_0043A5C8(s8 *arg0, s32 arg1, s32 arg2) {
    func_00104838(arg0);
    func_00104A48((s32) arg0, arg1, arg2);
    ((struct func_0043A5C8_arg0 *)arg0)->unk4 = 0;
    func_00104B10(arg0);
}
