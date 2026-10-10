#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005530B0_arg0 {
    char pad0[0x16B];
    u8 unk16B;
};

u8 func_005530B0(struct func_005530B0_arg0 *arg0) {
    return arg0->unk16B;
}
