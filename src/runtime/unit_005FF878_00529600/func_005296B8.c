#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_005296B8_arg0 {
    char pad0[0x34];
    s32 unk34;
};

s32 func_005296B8(struct func_005296B8_arg0 *arg0) {
    return arg0->unk34;
}
