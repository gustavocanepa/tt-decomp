#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_003FDC18_arg0 {
    char pad0[0x1718];
    s32 unk1718;
};

s32 func_003FDC18(struct func_003FDC18_arg0 *arg0) {
    return *(s32 *)(0x585670 + (arg0->unk1718 * 4));
}
