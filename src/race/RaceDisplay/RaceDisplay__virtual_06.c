#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct RaceDisplay__virtual_06_arg0 {
    char pad0[0x1C];
    s32 unk1C;
    char pad20[0x1C];
    s32 unk3C;
};

void RaceDisplay__virtual_06(struct RaceDisplay__virtual_06_arg0 *arg0, s32 arg1) {
    arg0->unk1C = arg1;
    arg0->unk3C = (s32) (arg0->unk3C & 0xFFFFFF);
}
