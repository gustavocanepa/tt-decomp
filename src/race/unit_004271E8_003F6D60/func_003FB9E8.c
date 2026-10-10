#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00408720(s32, s32);                    /* extern */
s32 func_00408C18(s32, s32);                    /* extern */

struct func_003FB9E8_arg0 {
    char pad0[0x8210];
    s32 unk8210;
};

void func_003FB9E8(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_s0;

    temp_s0 = arg0 + 0x7D08;
    func_00408720(temp_s0, arg2);
    func_00408C18(temp_s0, arg3);
    ((struct func_003FB9E8_arg0 *)arg0)->unk8210 = arg1;
}
