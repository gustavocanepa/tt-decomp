#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00558810_arg0 {
    char pad0[0x18];
    s32 unk18;
};

void func_00558810(struct func_00558810_arg0 *arg0, s32 arg1) {
    arg0->unk18 = (s32) ((arg0->unk18 & 0xFFFF00FF) | ((arg1 & 0xFF) << 8));
}
