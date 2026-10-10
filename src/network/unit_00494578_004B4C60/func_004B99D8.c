#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004B8A18(s32, s32, s32, s32, s32);         /* extern */
s32 func_004A4D68(s32);                         /* extern */
s32 func_004A4DD8(s32);                         /* extern */

extern char D_0059834C[];
s32 func_004B99D8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_s1;

    func_004A4D68(*(s32 *)(s32)D_0059834C + 0x34);
    temp_s1 = func_004B8A18(arg0, arg1, arg2, arg3, arg4);
    func_004A4DD8(*(s32 *)(s32)D_0059834C + 0x34);
    return temp_s1;
}
