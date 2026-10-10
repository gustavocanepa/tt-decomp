#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A5880(s32);                         /* extern */

struct func_0047D0F0_arg0 {
    char pad0[0x94];
    s32 unk94;
};

void func_0047D0F0(struct func_0047D0F0_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk94;
    if (temp_v0 != 0) {
        func_004A5880(temp_v0);
        arg0->unk94 = 0;
    }
}
