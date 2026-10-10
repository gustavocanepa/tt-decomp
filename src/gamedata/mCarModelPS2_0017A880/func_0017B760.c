#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0017B760_temp_a0 {
    char pad0[0x84];
    f32 unk84;
    f32 unk88;
    f32 unk8C;
};

void func_0017B760(s32 arg0, f32 fparg0, f32 fparg1, f32 fparg2) {
    struct func_0017B760_temp_a0 *temp_a0;

    temp_a0 = arg0 + 0xB3C;
    temp_a0->unk84 = fparg0;
    temp_a0->unk88 = fparg1;
    temp_a0->unk8C = fparg2;
}
