#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565BB8_arg0 {
    char pad0[0x43];
    u8 unk43;
};

u8 func_00565BB8(struct func_00565BB8_arg0 *arg0) {
    return arg0->unk43;
}
