#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0019B948_arg0 {
    char pad0[0x48];
    u16 unk48;
};

void func_0019B948(struct func_0019B948_arg0 *arg0, s32 arg1) {
    u16 temp_v0;

    temp_v0 = arg0->unk48;
    if (arg1 != 0) {
        arg0->unk48 = (u16) (temp_v0 | 8);
        return;
    }
    arg0->unk48 = (u16) (temp_v0 & 0xFFF7);
}
