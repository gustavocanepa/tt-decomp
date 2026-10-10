#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004B3548_arg0 {
    s32 unk0;
    u8 *unk4;
};

void func_004B3548(struct func_004B3548_arg0 *arg0) {
    u8 *temp_v0;
    u8 *temp_v1;
    u8 temp_v0_2;

loop_1:
    temp_v0 = arg0->unk4;
    temp_v1 = temp_v0 - 1;
    if (temp_v0 != arg0->unk0) {
        arg0->unk4 = temp_v1;
        temp_v0_2 = *temp_v1;
        if (temp_v0_2 & 0x80) {
            if (!(temp_v0_2 & 0xC0)) {
                goto loop_1;
            }
        }
    }
}
