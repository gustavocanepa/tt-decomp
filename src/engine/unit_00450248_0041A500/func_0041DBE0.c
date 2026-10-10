#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F7A30(s32, s32);                    /* extern */
s32 func_004F7B74(s32, s32);                /* extern */

extern char D_00600070[];
s32 func_0041DBE0(s32 arg0, s32 arg1) {
    func_004F7B74(arg1, (s32)D_00600070);
    func_004F7A30(arg1, arg0);
    return arg1;
}
