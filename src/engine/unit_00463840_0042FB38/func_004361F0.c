#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004361F0_temp_a0 {
    char pad0[0x51];
    s8 unk51;
};
struct func_004361F0_arg1 {
    char pad0[0x564];
    u8 unk564;
};

void func_004361F0(s32 arg0, struct func_004361F0_arg1 *arg1) {
    struct func_004361F0_temp_a0 *temp_a0;

    temp_a0 = arg0 + 0x14;
    if (temp_a0->unk51 == arg1->unk564) {
        temp_a0->unk51 = -1;
    }
}
