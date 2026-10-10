#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 AutomobileControlRecord__Manager__load(s32, s32, s32);               /* extern */
void *func_00386940();                              /* extern */

struct func_003873A8_temp_v0 {
    char pad0[0x1D0];
    s32 unk1D0;
};

void func_003873A8(s32 arg0, s32 arg1, s32 arg2) {
    void *temp_v0;

    temp_v0 = func_00386940();
    AutomobileControlRecord__Manager__load(temp_v0 + 0xD4, arg1 + 0x1A24, arg2);
    ((struct func_003873A8_temp_v0 *)temp_v0)->unk1D0 = 0;
}
