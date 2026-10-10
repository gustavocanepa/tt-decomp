#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_001DA7D8();                            /* extern */
f32 func_00205D10(s32);                             /* extern */
f32 func_00205D70(s32);                             /* extern */

struct func_00279E58_arg0 {
    char pad0[0xBC];
    s32 unkBC;
    char padC0[0x48];
    f32 unk108;
    f32 unk10C;
};

void func_00279E58(struct func_00279E58_arg0 *arg0) {
    s32 temp_s0;

    func_001DA7D8();
    temp_s0 = arg0->unkBC;
    if (temp_s0 != 0) {
        arg0->unk108 = func_00205D10(temp_s0);
        arg0->unk10C = func_00205D70(temp_s0);
    }
}
