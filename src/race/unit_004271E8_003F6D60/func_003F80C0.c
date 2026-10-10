#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003F80C0_arg0 {
    char pad0[0xD4];
    s32 unkD4;
};

void func_003F80C0(struct func_003F80C0_arg0 *arg0, s32 arg1) {
    s32 temp_v0;

    temp_v0 = arg0->unkD4 & ~2;
    arg0->unkD4 = (s32) ((arg1 != 0) ? (temp_v0 | 2) : temp_v0);
}
