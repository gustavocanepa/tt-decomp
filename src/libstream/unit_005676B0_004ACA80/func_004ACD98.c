#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_004A4D68(s32);                         /* extern */
s32 func_004A4DD8(s32);                         /* extern */
s32 func_004AC980(s32);                             /* extern */

s32 func_004ACD98(s32 arg0) {
    s32 temp_s0;
    s32 temp_s1;

    temp_s1 = arg0 + 0xC;
    func_004A4D68(temp_s1);
    temp_s0 = func_004AC980(arg0);
    func_004A4DD8(temp_s1);
    return temp_s0;
}
