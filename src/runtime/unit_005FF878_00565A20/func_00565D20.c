#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565D20_arg0 {
    char pad0[0x3C];
    u8 unk3C;
};

u8 func_00565D20(struct func_00565D20_arg0 *arg0) {
    return arg0->unk3C;
}
