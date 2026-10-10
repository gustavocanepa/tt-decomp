#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002F4A90_temp_a0 {
    char pad0[0x624];
    s32 unk624;
    s8 unk628;
};

void func_002F4A90(s32 arg0) {
    struct func_002F4A90_temp_a0 *temp_a0;

    temp_a0 = arg0 + 0x104;
    if (temp_a0->unk628 != 2) {
        temp_a0->unk624 = 0;
    }
}
