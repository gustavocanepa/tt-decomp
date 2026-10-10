#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 SPEC_DATABASE__GetLightEffect(s64);                             /* extern */

struct RaceBase__virtual_51_arg0_unk6C {
    char pad0[0x68];
    s64 unk68;
};
struct RaceBase__virtual_51_arg0 {
    char pad0[0x6C];
    struct RaceBase__virtual_51_arg0_unk6C *unk6C;
};

s32 RaceBase__getDefaultCarModelType(struct RaceBase__virtual_51_arg0 *arg0) {
    return (SPEC_DATABASE__GetLightEffect(arg0->unk6C->unk68) == 0) ? 0 : 3;
}
