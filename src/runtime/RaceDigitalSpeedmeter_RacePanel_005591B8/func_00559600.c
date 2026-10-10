#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00559600_arg0 {
    char pad0[0x108];
    s32 unk108;
};

void func_00559600(struct func_00559600_arg0 *arg0, s32 arg1) {
    arg0->unk108 = (s32) ((arg0->unk108 & ~0xFF) | (arg1 & 0xFF));
}
