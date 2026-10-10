#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002027E0(s32, void *);                 /* extern */
s32 func_001D7BC0(void *, s32);             /* extern */
s32 func_001C50D8(void *);                      /* extern */

s32 func_001C51A0(s32 arg0) {
    s8 sp[0x10];
    func_001C50D8(sp);
    func_002027E0(arg0, sp);
    func_001D7BC0(sp, 2);
    return arg0;
}
