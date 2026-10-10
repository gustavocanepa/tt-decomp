/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A4D68(s32);                         /* extern */
s32 func_004A4DD8(s32);                         /* extern */
s32 func_004AC8F0(s32, s32, s32);               /* extern */

void func_004ACCE0(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_s2;

    temp_s2 = arg0 + 0xC;
    func_004A4D68(temp_s2);
    func_004AC8F0(arg0, arg1, arg2);
    func_004A4DD8(temp_s2);
}
