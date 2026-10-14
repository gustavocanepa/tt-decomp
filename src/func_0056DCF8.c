#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_0056DCF8_arg0 {
    char pad0[0x4];
    s32 unk4;
};

u32 func_0056DCF8(struct func_0056DCF8_arg0 *arg0) {
    u8 *p = (u8 *)(arg0->unk4 + 0xC);
    return p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24);
}
