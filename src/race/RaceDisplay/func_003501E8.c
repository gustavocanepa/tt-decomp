#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003501E8_arg0 {
    char pad0[0x20];
    s32 unk20;
    char pad24[0x1C];
    s32 unk40;
};

void func_003501E8(struct func_003501E8_arg0 *arg0, s32 arg1) {
    arg0->unk20 = arg1;
    arg0->unk40 = (s32) ((arg0->unk40 & ~0xFF) | 1);
}
