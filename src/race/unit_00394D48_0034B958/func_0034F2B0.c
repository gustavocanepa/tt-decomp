#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_004A6120(f32, f32);
struct func_0034F2B0_arg0 {
    char pad0[0x10];
    f32 unk10;
};

f32 func_0034F2B0(struct func_0034F2B0_arg0 *arg0, f32 fparg0) {
    f32 temp_f20;

    temp_f20 = arg0->unk10;
    arg0->unk10 = func_004A6120(0x1.4000000000000p+3f, fparg0 / 0x1.4000000000000p+4f);
    return temp_f20;
}
