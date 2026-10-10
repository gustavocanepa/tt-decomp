#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_002FD9C0_arg1 {
    char pad0[0x5D8];
    u8 unk5D8;
};

u8 func_002FD9C0(s32 arg0, struct func_002FD9C0_arg1 *arg1) {
    return arg1->unk5D8;
}
