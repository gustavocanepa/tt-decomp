#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004A45D0(s32);                         /* extern */

struct func_001B3F20_arg0 {
    char pad0[0x10];
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

void func_001B3F20(struct func_001B3F20_arg0 *arg0) {
    s32 temp_a0;

    if (arg0->unk18 != 0) {
        temp_a0 = arg0->unk10;
        arg0->unk10 = 0;
        func_004A45D0(temp_a0);
        arg0->unk14 = 0;
        arg0->unk18 = 0;
    }
}
