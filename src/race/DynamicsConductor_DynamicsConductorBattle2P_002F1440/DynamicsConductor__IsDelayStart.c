#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct DynamicsConductorBattle2P__virtual_40_arg0 {
    char pad0[0x23940];
    s16 unk23940;
};

s32 DynamicsConductor__IsDelayStart(struct DynamicsConductorBattle2P__virtual_40_arg0 *arg0) {
    return arg0->unk23940 != 0;
}
