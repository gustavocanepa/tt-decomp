#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005CE068[];
struct RaceBGMBase__structor_0_arg0 {
    char pad0[0x4];
    s32 unk4;
};

s32 RaceBGMBase__structor_0(struct RaceBGMBase__structor_0_arg0 *arg0) {
    arg0->unk4 = (s32)D_005CE068;
}
