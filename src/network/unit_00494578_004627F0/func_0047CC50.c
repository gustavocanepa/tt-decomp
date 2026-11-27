/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

M2C_UNK func_004AEB30(s32);                         /* extern */
void func_004A4D68(void *);                      /* extern */
M2C_UNK func_004A4DD8(void *);                      /* extern */
M2C_UNK func_004AC838(s32, void *);                 /* extern */

void func_0047CC50(s32 arg0, void *arg1) {
    void *temp_s2;

    temp_s2 = arg0 + 0x10;
    func_004A4D68(temp_s2);
    func_004A4D68(arg1);
    M2C_FIELD(arg1, s32 *, 0x80) = 1;
    func_004AC838(arg0 + 0x4C, arg1 + 0x3C);
    func_004A4DD8(arg1);
    func_004AEB30(arg0 + 0x64);
    func_004A4DD8(temp_s2);
}
