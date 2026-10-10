#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003C7528(void *);                      /* extern */
s32 func_003E6350(s32, s32, void *);            /* extern */

s32 func_003C7598(s32 arg0, s32 arg1) {
    s8 sp[0x10];
    func_003C7528(sp);
    func_003E6350(arg0, arg1 + 0xC0, sp);
    return arg0;
}
