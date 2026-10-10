#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001E6318_arg0 {
    char pad0[0x1D54];
    s32 unk1D54;
};

void func_001E6318(struct func_001E6318_arg0 *arg0) {
    arg0->unk1D54 = (s32) (arg0->unk1D54 ^ 1);
}
