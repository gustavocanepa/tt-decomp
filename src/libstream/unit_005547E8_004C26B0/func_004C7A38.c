#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_004C7A38_arg0 {
    char pad0[0x20];
    s8 unk20;
    char pad21[0x67];
    s32 unk88;
};

void func_004C7A38(struct func_004C7A38_arg0 *arg0, s32 arg1) {
    arg0->unk88 = arg1;
    arg0->unk20 = 1;
}
