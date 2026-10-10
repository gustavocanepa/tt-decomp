#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 AutomobileControlRecord__Manager__load(s32, s32, s32);           /* extern */
void *func_00386980();                              /* extern */

struct func_00386EB8_temp_v0 {
    char pad0[0x1D0];
    s32 unk1D0;
};

void func_00386EB8(s32 arg0, s32 arg1) {
    void *temp_v0;

    temp_v0 = func_00386980();
    AutomobileControlRecord__Manager__load(temp_v0 + 0xD4, arg1 + 0x1A24, 1);
    ((struct func_00386EB8_temp_v0 *)temp_v0)->unk1D0 = 0;
}
