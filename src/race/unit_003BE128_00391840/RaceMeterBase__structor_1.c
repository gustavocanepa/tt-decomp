#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern char D_005D5CB8[];
s32 RaceDisplayObjectBase__structor_0(void *);
struct RaceMeterBase__structor_1_arg0 {
    s32 unk0;
    char pad4[0x10];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
};

void RaceMeterBase__structor_1(struct RaceMeterBase__structor_1_arg0 *arg0) {
    RaceDisplayObjectBase__structor_0(arg0);
    arg0->unk14 = (s32)D_005D5CB8;
    arg0->unk0 = (s32) ((arg0->unk0 & ~0xFF) | 1);
    arg0->unk1C = 0;
    arg0->unk20 = 0;
    arg0->unk18 = 0;
}
