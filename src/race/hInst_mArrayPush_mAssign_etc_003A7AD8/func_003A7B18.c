#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003A7A58();                            /* extern */

struct func_003A7B18_arg0 {
    char pad0[0x88];
    f32 unk88;
};

void func_003A7B18(struct func_003A7B18_arg0 *arg0, s32 arg1, f32 *arg2) {
    f32 temp_f20;

    temp_f20 = arg0->unk88;
    *arg2 = 0x1.0000000000000p+0f;
    func_003A7A58();
    if (temp_f20 != 0x0.0p+0f) {
        *arg2 = (0x1.0000000000000p+1f * (0x1.0000000000000p-1f - temp_f20) * 0x1.6666660000000p-1f) + 0x1.3333320000000p-2f;
    }
}
