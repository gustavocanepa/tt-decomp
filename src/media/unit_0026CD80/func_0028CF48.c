#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0022C0D0(void *, s32);                 /* extern */
s32 func_0022C0E8(void *, s32);             /* extern */
s32 func_0028C808(void *, s32, s32);            /* extern */

struct func_0028CF48_arg0 {
    char pad0[0x410];
    s32 unk410;
};

void func_0028CF48(struct func_0028CF48_arg0 *arg0, s32 arg1, s32 arg2) {
    s8 sp[0x10];
    func_0022C0D0(sp, arg0->unk410 - 4);
    func_0028C808(arg0, arg1, arg2);
    func_0022C0E8(sp, 2);
}
