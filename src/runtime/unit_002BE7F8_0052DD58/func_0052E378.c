#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0052E378_arg0 {
    char pad0[0x38];
    f32 unk38;
    char pad3C[0x34];
    f32 unk70;
    s32 unk74;
};

void func_0052E378(struct func_0052E378_arg0 *arg0, f32 fparg0) {
    arg0->unk38 = fparg0;
    arg0->unk74 = 1;
    arg0->unk70 = fparg0;
}
