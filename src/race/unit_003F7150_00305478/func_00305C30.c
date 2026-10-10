#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00305C30_temp_a0 {
    char pad0[0x634];
    s32 unk634;
    char pad638[0x60];
    s16 unk698;
};

void func_00305C30(s32 arg0) {
    struct func_00305C30_temp_a0 *temp_a0;

    temp_a0 = arg0 + 0x104;
    temp_a0->unk698 = 0;
    temp_a0->unk634 = 0x157529FF;
}
