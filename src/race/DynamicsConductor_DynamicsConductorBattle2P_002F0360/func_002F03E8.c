#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002F03E8_arg0 {
    char pad0[0x20A24];
    u8 unk20A24;
    char pad20A25[0x1F];
    s16 unk20A44;
};

void func_002F03E8(struct func_002F03E8_arg0 *arg0, s32 arg1) {
    if (arg0->unk20A24 == 4) {
        arg0->unk20A44 = (s16) ((arg1 * 0x3C) + 1);
    }
}
