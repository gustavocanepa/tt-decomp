#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00535758(void *, f32, f32);                /* extern */
s32 func_00544038(void *, s32);                 /* extern */
s32 func_0055E690(void *);                          /* extern */

struct func_00396670_arg0 {
    char pad0[0x96E8];
    s32 unk96E8;
};

f32 func_00396670(struct func_00396670_arg0 *arg0, f32 fparg0, f32 fparg1) {
    s8 sp[0x10];
    f32 temp_f20;

    func_00544038(sp, arg0->unk96E8);
    temp_f20 = func_00535758(sp, fparg0, fparg1);
    arg0->unk96E8 = func_0055E690(sp);
    return temp_f20;
}
