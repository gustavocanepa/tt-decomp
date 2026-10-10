#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004014A0_arg0 {
    char pad0[0x28B8];
    s32 unk28B8;
};

void func_004014A0(struct func_004014A0_arg0 *arg0) {
    arg0->unk28B8 = 1;
}
