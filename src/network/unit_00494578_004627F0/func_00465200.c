#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00471E18(s32, s32, s32, s32);  /* extern */
s32 func_00472130(s32, s32);                    /* extern */
s32 func_00472268(s32, s32);            /* extern */
s32 func_00472528(s32, s32, s32);       /* extern */
void func_00472628();                            /* extern */

void func_00465200(s32 arg0, s32 arg1, s32 arg2) {
    func_00472628();
    func_00471E18(0, arg0, 0, (arg1 + 0x3F) & ~0x3F);
    func_00472130(arg1, arg2);
    func_00472528(0, 0, arg1);
    func_00472528(1, 0, arg2);
    func_00472268(4, 1);
    func_00472268(5, 1);
}
