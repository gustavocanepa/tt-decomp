/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

void func_004A4D68(s32);                         /* extern */
M2C_UNK func_004A4DD8(s32);                         /* extern */
M2C_UNK func_004A4F00(s32);                         /* extern */

void func_0047D938(void *arg0) {
    s32 temp_s1;

    temp_s1 = arg0 + 0x1838;
    func_004A4D68(temp_s1);
    M2C_FIELD(arg0, s32 *, 0x1868) = (s32) (M2C_FIELD(arg0, s32 *, 0x1868) - 1);
    func_004A4F00(temp_s1);
    func_004A4DD8(temp_s1);
}
