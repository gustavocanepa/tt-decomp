#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_001E6310_arg0 {
    char pad0[0x1D54];
    s32 unk1D54;
};

void func_001E6310(struct func_001E6310_arg0 *arg0, s32 arg1) {
    arg0->unk1D54 = arg1;
}
