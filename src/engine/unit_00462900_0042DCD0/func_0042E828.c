#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0042E060(f32, s32);                    /* extern */
s32 func_004A48C0(void *);                      /* extern */
s32 func_004A48D8(void *, s32);             /* extern */
s32 func_004A4930(void *);                      /* extern */
s32 func_004A4970(void *);                      /* extern */

void func_0042E828(s32 arg0, f32 fparg0) {
    s8 sp[0x10];
    func_004A48C0(sp);
    func_004A4930(sp);
    func_0042E060(fparg0, arg0);
    func_004A4970(sp);
    func_004A48D8(sp, 2);
}
