#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00302988_arg0 {
    char pad0[0x7E4];
    u8 unk7E4;
};

s32 func_00302988(struct func_00302988_arg0 *arg0) {
    return arg0->unk7E4 == 0x22;
}
