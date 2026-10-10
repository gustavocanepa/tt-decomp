#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004186B8_arg0 {
    char pad0[0x34C];
    s32 unk34C;
};

void func_004186B8(struct func_004186B8_arg0 *arg0, s32 arg1) {
    arg0->unk34C = arg1;
}
