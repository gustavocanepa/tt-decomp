/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005607F0();                            /* extern */
s32 func_00555E58(s32, s32);                    /* extern */

void func_0045D5E0(void *arg0, s32 arg1) {
    func_005607F0();
    func_00555E58((s32)((char *)arg0 + 0x4), arg1);
}
