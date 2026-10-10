#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001E4EA0();                                /* extern */
s32 func_00269400(s32, s32, void *, s32);       /* extern */

struct func_001E5710_arg0 {
    char pad0[0x1D50];
    s32 unk1D50;
};

void func_001E5710(struct func_001E5710_arg0 *arg0, s32 arg1) {
    s32 temp_s1;

    temp_s1 = arg0->unk1D50;
    func_00269400(temp_s1, arg1, arg0, func_001E4EA0());
}
