#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_00562CD8_arg0 {
    char pad0[0x1148];
    s32 unk1148;
};

s32 func_00562CD8(struct func_00562CD8_arg0 *arg0) {
    return ((s32) arg0->unk1148 >> 8) & 1;
}
