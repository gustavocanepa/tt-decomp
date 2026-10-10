#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0052E3B0_arg0 {
    char pad0[0x34];
    f32 unk34;
    f32 unk38;
    char pad3C[0x30];
    f32 unk6C;
    f32 unk70;
};

void func_0052E3B0(struct func_0052E3B0_arg0 *arg0) {
    arg0->unk6C = (f32) arg0->unk34;
    arg0->unk70 = (f32) arg0->unk38;
}
