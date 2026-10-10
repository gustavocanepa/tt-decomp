#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_00376C88(s32);                             /* extern */

struct RacePS2Base__virtual_142_arg0 {
    char pad0[0x6C];
    s32 unk6C;
    char pad70[0xCF88];
    f32 unkCFF8;
};

f32 RacePS2Base__getMasterVolume(struct RacePS2Base__virtual_142_arg0 *arg0) {
    return func_00376C88(arg0->unk6C) * arg0->unkCFF8;
}
