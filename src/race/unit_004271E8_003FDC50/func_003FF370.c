#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003FF370_temp_a0 {
    char pad0[0x7];
    u8 unk7;
};

void func_003FF370(void **arg0) {
    u8 temp_v0;
    struct func_003FF370_temp_a0 *temp_a0;

    temp_a0 = *arg0;
    temp_v0 = temp_a0->unk7;
    if ((temp_v0 & 6) == 6) {
        temp_a0->unk7 = (u8) (temp_v0 & 0xF9);
    }
}
