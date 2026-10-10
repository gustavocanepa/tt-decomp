#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004186E0_arg0 {
    char pad0[0x324];
    s32 unk324;
};

s32 func_004186E0(struct func_004186E0_arg0 *arg0) {
    return arg0->unk324;
}
