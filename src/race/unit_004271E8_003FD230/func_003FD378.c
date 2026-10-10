#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003FD378_arg0 {
    char pad0[0x1160];
    s32 unk1160;
};

s32 func_003FD378(struct func_003FD378_arg0 *arg0) {
    return *(s32 *)(0x585660 + (arg0->unk1160 * 4));
}
