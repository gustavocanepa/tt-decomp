#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00553198_arg0 {
    char pad0[0x16C];
    u8 unk16C;
};

u8 func_00553198(struct func_00553198_arg0 *arg0) {
    return arg0->unk16C;
}
