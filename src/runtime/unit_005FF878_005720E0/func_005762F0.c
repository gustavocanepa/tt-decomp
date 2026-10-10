#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005762F0_arg0 {
    char pad0[0x1A];
    u8 unk1A;
};

void func_005762F0(struct func_005762F0_arg0 *arg0, s32 arg1) {
    arg0->unk1A = (u8) (arg0->unk1A | arg1);
}
