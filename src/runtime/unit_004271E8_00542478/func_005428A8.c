#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005428A8_arg0 {
    char pad0[0x98];
    s32 unk98;
};

void func_005428A8(struct func_005428A8_arg0 *arg0, s32 arg1) {
    arg0->unk98 = arg1;
}
