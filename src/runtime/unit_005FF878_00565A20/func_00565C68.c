#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00565C68_arg0 {
    char pad0[0x5F];
    u8 unk5F;
};

u8 func_00565C68(struct func_00565C68_arg0 *arg0) {
    return arg0->unk5F;
}
