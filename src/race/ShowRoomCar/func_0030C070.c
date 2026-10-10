#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_002F3A88(s32, s32, s32);               /* extern */
f32 func_002FABA0(s32);                             /* extern */

struct func_0030C070_temp_s0 {
    char pad0[0x1768];
    f32 unk1768;
};

void func_0030C070(void **arg0, s32 arg1) {
    void *temp_s0;

    temp_s0 = *arg0;
    func_002F3A88(temp_s0 + 0x740, temp_s0 + 0x1768, arg1);
    ((struct func_0030C070_temp_s0 *)temp_s0)->unk1768 = (f32) (((struct func_0030C070_temp_s0 *)temp_s0)->unk1768 + func_002FABA0(temp_s0 + 0x840));
}
