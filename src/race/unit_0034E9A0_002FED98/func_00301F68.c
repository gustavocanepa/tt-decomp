#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00301F68_arg0 {
    char pad0[0x7E5];
    u8 unk7E5;
};

s32 func_00301F68(struct func_00301F68_arg0 *arg0) {
    return arg0->unk7E5 & 0xF;
}
