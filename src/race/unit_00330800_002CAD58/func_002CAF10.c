#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002CAF10_arg0 {
    char pad0[0x20C];
    f32 unk20C;
};

void func_002CAF10(struct func_002CAF10_arg0 *arg0, f32 fparg0) {
    f32 temp_f12;

    temp_f12 = fparg0 / 0x1.1111100000000p-6f;
    arg0->unk20C = temp_f12;
    if (temp_f12 > 0x1.0000000000000p+0f) {
        arg0->unk20C = 0x1.0000000000000p+0f;
    }
}
