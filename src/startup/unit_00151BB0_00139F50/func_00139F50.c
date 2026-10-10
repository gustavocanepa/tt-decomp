#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00139BC8(s32, void *);                 /* extern */
s32 func_00178200(void *, s32);             /* extern */
s32 func_0017BBD8(void *);                      /* extern */

s32 func_00139F50(s32 arg0) {
    s8 sp[0x10];
    func_0017BBD8(sp);
    func_00139BC8(arg0, sp);
    func_00178200(sp, 2);
    return arg0;
}
