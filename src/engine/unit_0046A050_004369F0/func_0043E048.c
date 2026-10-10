#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0043D3B8(void *, s32 *);               /* extern */
s32 func_0043D510(void *);                      /* extern */
s32 strobe__Any__toString(void *);                          /* extern */
s32 strobe__Any__typeOf(s32 *);                           /* extern */
s32 func_004A6448(s32, s32, s32, s32);      /* extern */

void func_0043E048(s32 *arg0) {
    s8 sp[0x10];
    s32 temp_s1;

    func_0043D3B8(sp, arg0);
    temp_s1 = strobe__Any__typeOf(arg0);
    func_004A6448((s32)"type : %s(%d)  val : %s\012", temp_s1, *arg0, strobe__Any__toString(sp));
    func_0043D510(sp);
}
