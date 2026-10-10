#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003C7058(s32, s32, void *);            /* extern */
s32 func_003C74B0(void *);                      /* extern */

s32 func_003C71C0(s32 arg0, s32 arg1) {
    s8 sp[0x10];
    func_003C74B0(sp);
    func_003C7058(arg0, arg1, sp);
    return arg0;
}
