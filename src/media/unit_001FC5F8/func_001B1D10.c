#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00104868(s32, s32);                /* extern */
s32 func_001071E8(s32, s32);                /* extern */
s32 func_001B1E50();                            /* extern */
s32 func_00216870(s32, s32);                /* extern */
s32 func_004AE9F0(s32, s32);                /* extern */
s32 func_0050E1A8(s32);                         /* extern */

void func_001B1D10(s32 arg0, s32 arg1) {
    func_001B1E50();
    func_00216870(arg0 + 0xE8, 2);
    func_004AE9F0(arg0 + 0x8C, 2);
    func_001071E8(arg0 + 0x40, 2);
    func_00104868(arg0, 2);
    if (arg1 & 1) {
        func_0050E1A8(arg0);
    }
}
