#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001E4380_arg0 {
    char pad0[0x1D1C];
    f32 unk1D1C;
    char pad1D20[0x8];
    f32 unk1D28;
};

void func_001E4380(struct func_001E4380_arg0 *arg0, f32 *arg1, f32 *arg2) {
    *arg1 = arg0->unk1D1C;
    *arg2 = arg0->unk1D28;
}
