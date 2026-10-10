/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00304FC0(s32);                             /* extern */
s32 func_003527E8(void *, s32);                 /* extern */

struct RaceLicenseDisplay__virtual_27_arg0 {
    char pad0[0x10];
    s32 unk10;
};

void RaceLicenseDisplay__set_automobile_message(struct RaceLicenseDisplay__virtual_27_arg0 *arg0, s32 arg1) {
    if ((func_00304FC0(arg0->unk10) <= 0) || (arg1 >= 4) || (arg1 < 2)) {
        func_003527E8(arg0, arg1);
    }
}
