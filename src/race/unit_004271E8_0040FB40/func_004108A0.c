#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004108A0_arg0 {
    char pad0[0x13];
    u8 unk13;
};

u32 func_004108A0(struct func_004108A0_arg0 *arg0) {
    return (u8) arg0->unk13 % 100U;
}
