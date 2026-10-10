#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0030BFE0(void *);                      /* extern */
s32 ShowRoomCar__structor_1(void *, s32);             /* extern */
s32 func_0030C0C0(void *, s32, s32, s32); /* extern */
f32 func_0030C870(void *);                          /* extern */

f32 func_00176FF8(s32 arg0) {
    s8 sp[0x10];
    f32 temp_f20;

    func_0030BFE0(sp);
    func_0030C0C0(sp, arg0, 0, 0);
    temp_f20 = func_0030C870(sp);
    ShowRoomCar__structor_1(sp, 2);
    return temp_f20;
}
