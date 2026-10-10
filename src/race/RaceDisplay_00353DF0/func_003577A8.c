#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003577A8_arg0 {
    char pad0[0x44];
    s32 unk44;
    char pad48[0x4];
    s32 unk4C;
};

void func_003577A8(struct func_003577A8_arg0 *arg0, s32 arg1) {
    if (arg0->unk4C != arg1) {
        arg0->unk4C = arg1;
        arg0->unk44 = (s32) ((arg0->unk44 & 0xFFFF00FF) | 0x100);
    }
}
