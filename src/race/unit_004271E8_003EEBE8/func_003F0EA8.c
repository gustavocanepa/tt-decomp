#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003F0EA8_arg0 {
    char pad0[0x14];
    u16 unk14;
};

u16 func_003F0EA8(struct func_003F0EA8_arg0 *arg0) {
    return arg0->unk14;
}
