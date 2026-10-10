#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00364328_arg0 {
    char pad0[0x38];
    s32 unk38;
    char pad3C[0x8];
    f32 unk44;
};

void func_00364328(struct func_00364328_arg0 *arg0, s32 arg1, f32 fparg0) {
    arg0->unk44 = fparg0;
    arg0->unk38 = (s32) ((arg0->unk38 & 0xFFFFFF) | (arg1 << 0x18));
}
