#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002FB6B8(s32, void *);                 /* extern */
s32 func_002FB6E8(s32, void *);                 /* extern */
s32 func_00305C78(void *);                      /* extern */
s32 func_003A36A0(s32);                             /* extern */

struct DynamicsConductorLicense__virtual_33_arg1 {
    char pad0[0x5D6];
    u8 unk5D6;
};

void DynamicsConductorLicense__CurrentLapTime(s32 arg0, struct DynamicsConductorLicense__virtual_33_arg1 *arg1) {
    if (arg1->unk5D6 != 0) {
        func_00305C78(arg1);
        return;
    }
    if (func_003A36A0(arg0 + 0x238E0) == 0) {
        func_002FB6B8(arg0, arg1);
        return;
    }
    func_002FB6E8(arg0, arg1);
}
