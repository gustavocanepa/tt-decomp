/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00420430(void *, f32);                     /* extern */

struct func_00421B88_arg0 {
    char pad0[0x16];
    u16 unk16;
    char pad18[0x20];
    s32 unk38;
};

struct func_00421B88_temp_a0 {
    char pad0[0x8];
    f32 unk8;
};

f32 func_00421B88(struct func_00421B88_arg0 *arg0, s32 arg1) {
    void *temp_a0;

    if ((arg1 >= (s32) arg0->unk16) || (arg1 < 0)) {
        return 0x0.0p+0f;
    }
    temp_a0 = arg0->unk38 + (arg1 * 0x28);
    return func_00420430(temp_a0 + 0xC, ((struct func_00421B88_temp_a0 *)temp_a0)->unk8);
}
