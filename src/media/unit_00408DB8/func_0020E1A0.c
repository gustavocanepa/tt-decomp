#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0020DC50();                                /* extern */

struct func_0020E1A0_arg0 {
    char pad0[0x5C];
    void *unk5C;
    char pad60[0x50];
    s32 unkB0;
};
struct func_0020E1A0_temp_a1 {
    char pad0[0x30];
    u32 unk30;
};

void func_0020E1A0(struct func_0020E1A0_arg0 *arg0, s32 arg1) {
    u32 temp_a0;
    struct func_0020E1A0_temp_a1 *temp_a1;

    if (func_0020DC50() != 0) {
        temp_a1 = arg0->unk5C;
        temp_a0 = temp_a1->unk30;
        if (((temp_a0 >> 4) & 3) != arg1) {
            temp_a1->unk30 = (u32) ((temp_a0 & ~0x30) | ((arg1 & 3) * 0x10));
            arg0->unkB0 = (s32) (arg0->unkB0 | 0x10);
        }
    }
}
